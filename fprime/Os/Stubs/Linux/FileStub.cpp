#include <Fw/Cfg/Config.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Os/File.hpp>
#include <Fw/Types/Assert.hpp>
#include <Os/Stubs/FileStubs.hpp>

#include <cerrno>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <string.h>
#include <stdio.h>

namespace Os {

    static ReadIntercepter readInterceptor = 0;
    static void *readInterceptorPtr = 0;

    static WriteIntercepter writeInterceptor = 0;
    static void *writeInterceptorPtr = 0;

    static OpenIntercepter openInterceptor = 0;
    static void *openInterceptorPtr = 0;

    static SeekIntercepter seekInterceptor = 0;
    static void *seekInterceptorPtr = 0;

    static NATIVE_INT_TYPE lastError = 0;

    void registerReadInterceptor(ReadIntercepter funcPtr, void *ptr) {
        readInterceptor = funcPtr;
        readInterceptorPtr = ptr;
    }

    void clearReadInterceptor(void) {
        readInterceptor = 0;
    }

    void registerWriteInterceptor(WriteIntercepter funcPtr, void *ptr) {
        writeInterceptor = funcPtr;
        writeInterceptorPtr = ptr;
    }

    void clearWriteInterceptor(void) {
        writeInterceptor = 0;
    }

    void registerOpenInterceptor(OpenIntercepter funcPtr, void *ptr) {
        openInterceptor = funcPtr;
        openInterceptorPtr = ptr;
    }

    void clearOpenInterceptor(void) {
        openInterceptor = 0;
    }

    void registerSeekInterceptor(SeekIntercepter funcPtr, void *ptr) {
        seekInterceptor = funcPtr;
        seekInterceptorPtr = ptr;
    }

    void clearSeekInterceptor(void) {
        seekInterceptor = 0;
    }

    void setLastError(NATIVE_INT_TYPE error) {
        lastError = error;
    }


    File::File() :m_fd(0),m_mode(OPEN_NO_MODE),m_lastError(0) {
    }

    File::~File() {
        if (this->m_mode != OPEN_NO_MODE) {
            this->close();
        }
    }

    File::Status File::open(const char* fileName, File::Mode mode) {

        if (openInterceptor) {
            File::Status stat;
            if (not openInterceptor(stat,fileName,mode,openInterceptorPtr)) {
                return stat;
            }
        }

        NATIVE_INT_TYPE flags = 0;
        Status stat = OP_OK;

        switch (mode) {
            case OPEN_READ:
                flags = O_RDONLY;
                break;
            case OPEN_WRITE:
                flags = O_WRONLY | O_CREAT | O_TRUNC;
                break;
            default:
                FW_ASSERT(0,(NATIVE_INT_TYPE)mode);
                break;
        }

        NATIVE_INT_TYPE userFlags = 
#ifdef __VXWORKS__
        0;
#else
        S_IRUSR|S_IWRITE;
#endif
        NATIVE_INT_TYPE fd = ::open(fileName,flags,userFlags);

        if (-1 == fd) {
            this->m_lastError = errno;
            switch (errno) {
                case ENOSPC:
                    stat = NO_SPACE;
                    break;
                case ENOENT:
                    stat = DOESNT_EXIST;
                    break;
                case EACCES:
                    stat = NO_PERMISSION;
                    break;
                default:
                    stat = OTHER_ERROR;
                    break;
            }
        }

        this->m_mode = mode;
        this->m_fd = fd;
        return stat;
    }

    File::Status File::seek(NATIVE_INT_TYPE offset, bool absolute) {

        if (seekInterceptor) {
            File::Status stat;
            if (not seekInterceptor(stat,offset,absolute,seekInterceptorPtr)) {
                return stat;
            }
        }


        // make sure it has been opened
        if (OPEN_NO_MODE == this->m_mode) {
            return NOT_OPENED;
        }

        Status stat = OP_OK;
        NATIVE_INT_TYPE whence = absolute?SEEK_SET:SEEK_CUR;

        off_t act_off = ::lseek(this->m_fd,offset,whence);

        // No error would be a normal one for this simple
        // class, so return other error
        if (act_off != offset) {
            if (-1 == act_off) {
                this->m_lastError = errno;
                stat = OTHER_ERROR;
            } else {
                stat = BAD_SIZE;
            }
        }

        return stat;
    }

    File::Status File::read(void * buffer, NATIVE_INT_TYPE &size, bool waitForFull) {

        FW_ASSERT(buffer);

        if (readInterceptor) {
            File::Status stat;
            if (not readInterceptor(stat,buffer,size,waitForFull,readInterceptorPtr)) {
                return stat;
            }
        }

        // make sure it has been opened
        if (OPEN_NO_MODE == this->m_mode) {
            return NOT_OPENED;
        }

        NATIVE_INT_TYPE accSize = 0; // accumulated size

        Status stat = OP_OK;

        NATIVE_INT_TYPE maxIters = size*2; // loop limit; couldn't block more times than number of bytes

        while (maxIters > 0) {

            ssize_t readSize = ::read(this->m_fd,
#ifdef __VXWORKS__
	       static_cast<char*>(buffer)
#else
               buffer
#endif
               ,size-accSize);

            if (readSize != size-accSize) {
                // could be an error
                if (-1 == readSize) {
                    switch (errno) {
                        case EINTR: // read was interrupted
                            maxIters--; // decrement loop count
                            continue;
                        default:
                            stat = OTHER_ERROR;
                            break;
                    }
                    this->m_lastError = errno;
                    accSize = 0;
                    break; // break out of while loop
                } else if (0 == readSize) { // end of file
                    accSize = 0;
                    break;
                } else { // partial read so adjust read point and size
                    accSize += readSize;
                    if (not waitForFull) {
                        break; // break out of while loop
                    } else {
                        // in order to move the pointer ahead, we need to cast it
                        U8* charPtr = (U8*)buffer;
                        charPtr = &charPtr[readSize];
                        buffer = (void*)charPtr;
                    }
                    maxIters--; // decrement loop count
                }

            } else { // got number we wanted
                accSize += readSize;
                break; // break out of while loop
            }

            maxIters--; // decrement loop count

        } // end read while loop

        // make sure we didn't exceed loop count
        FW_ASSERT(maxIters > 0);

        size = accSize;

        return stat;
    }

    File::Status File::write(const void * buffer, NATIVE_INT_TYPE &size, bool waitForDone) {

        if (writeInterceptor) {
            File::Status stat;
            if (not writeInterceptor(stat,buffer,size,waitForDone,writeInterceptorPtr)) {
                return stat;
            }
        }

        // make sure it has been opened
        if (OPEN_NO_MODE == this->m_mode) {
            return NOT_OPENED;
        }

        Status stat = OP_OK;
        // just check for EINTR
        NATIVE_INT_TYPE maxIters = size*2; // loop limit; couldn't block more times than number of bytes
        while (maxIters > 0) {
            NATIVE_INT_TYPE writeSize = ::write(this->m_fd,
#ifdef __VXWORKS__
	       static_cast<char*>(const_cast<void*>(buffer)) // Ugly, but that's how VxWorks likes to roll...
#else
               buffer
#endif
               ,size);
            if (-1 == writeSize) {
                switch (errno) {
                    case EINTR: // write was interrupted
                        maxIters--; // decrement loop count
                        continue;
                    case ENOSPC:
                        stat = NO_SPACE;
                        break;
                    default:
                        stat = OTHER_ERROR;
                        break;
                }
                this->m_lastError = errno;
                break; // break out of while loop
            } else {
                size = writeSize;
                break; // break out of while loop
            }
        }

        return stat;
    }

    void File::close(void) {
        (void)::close(this->m_fd);
        this->m_mode = OPEN_NO_MODE;
    }

    NATIVE_INT_TYPE File::getLastError(void) {
        return lastError;
    }

    const char* File::getLastErrorString(void) {
        return strerror(this->m_lastError);
    }



}

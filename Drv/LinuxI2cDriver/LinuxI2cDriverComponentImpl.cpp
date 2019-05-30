// ======================================================================
// \title  LinuxI2cDriverComponentImpl.cpp
// \author tcanham
// \brief  cpp file for LinuxI2cDriver component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Drv/LinuxI2cDriver/LinuxI2cDriverComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"
#include "Fw/Types/Assert.hpp"

#include <unistd.h> // required for I2C device access
#include <fcntl.h>  // required for I2C device configuration
#include <sys/ioctl.h> // required for I2C device usage
#include <linux/i2c-dev.h> // required for constant definitions
#include <stdio.h>  // required for printf statements
#include <errno.h>

namespace Drv {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  LinuxI2cDriverComponentImpl ::
#if FW_OBJECT_NAMES == 1
    LinuxI2cDriverComponentImpl(
        const char *const compName
    ) :
      LinuxI2cDriverComponentBase(compName)
#else
    LinuxI2cDriverComponentImpl(void)
#endif
	,m_fd(-1)
  {

  }

  void LinuxI2cDriverComponentImpl ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {
    LinuxI2cDriverComponentBase::init(instance);
  }

  LinuxI2cDriverComponentImpl ::
    ~LinuxI2cDriverComponentImpl(void)
  {

  }

  void LinuxI2cDriverComponentImpl::open(char* device) {
	  FW_ASSERT(device);
	  this->m_fd = ::open(device, O_RDWR);
	  FW_ASSERT(-1 != this->m_fd);
  }


  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  // Note this this port handler is guarded, so we can make the ioctl call

  void LinuxI2cDriverComponentImpl ::
    write_handler(
        const NATIVE_INT_TYPE portNum,
        U32 addr,
        Fw::Buffer &serBuffer
    )
  {
	  // Make sure file has been opened
	  FW_ASSERT(-1 != this->m_fd);

	  // select slave address
	  int stat = ioctl(this->m_fd, I2C_SLAVE, addr);
	  FW_ASSERT(-1 != stat,errno);
	  // make sure it isn't a null pointer
	  FW_ASSERT(serBuffer.getdata());
	  // write data
	  stat = write(this->m_fd,(void*) serBuffer.getdata(), serBuffer.getsize());
	  FW_ASSERT(-1 != stat,errno);

  }

} // end namespace Drv

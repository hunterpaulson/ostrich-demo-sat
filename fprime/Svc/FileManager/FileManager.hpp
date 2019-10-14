// ====================================================================== 
// \title  FileManager.hpp
// \author bocchino
// \brief  hpp file for FileManager component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged. Any commercial use must be negotiated with the Office
// of Technology Transfer at the California Institute of Technology.
// 
// This software may be subject to U.S. export control laws and
// regulations.  By accepting this document, the user agrees to comply
// with all U.S. export laws and regulations.  User has the
// responsibility to obtain export licenses, or other export authority
// as may be required before exporting such information to foreign
// countries or providing access to foreign persons.
// ====================================================================== 

#ifndef Svc_FileManager_HPP
#define Svc_FileManager_HPP

#include "Svc/FileManager/FileManagerComponentAc.hpp"
#include "Os/FileSystem.hpp"

namespace Svc {

  class FileManager :
    public FileManagerComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object FileManager
      //!
      FileManager(
          const char *const compName //!< The component name
      );

      //! Initialize object FileManager
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, //!< The queue depth
          const NATIVE_INT_TYPE instance //!< The instance number
      );

      //! Destroy object FileManager
      //!
      ~FileManager(void);

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations 
      // ----------------------------------------------------------------------

      //! Implementation for CreateDirectory command handler
      //!
      void CreateDirectory_cmdHandler(
          const FwOpcodeType opCode, //!< The opcode
          const U32 cmdSeq, //!< The command sequence number
          const Fw::CmdStringArg& dirName //!< The directory to create
      );

      //! Implementation for RemoveFile command handler
      //!
      void RemoveFile_cmdHandler(
          const FwOpcodeType opCode, //!< The opcode
          const U32 cmdSeq, //!< The command sequence number
          const Fw::CmdStringArg& fileName //!< The file to remove
      );

      //! Implementation for MoveFile command handler
      //!
      void MoveFile_cmdHandler(
          const FwOpcodeType opCode, //!< The opcode
          const U32 cmdSeq, //!< The command sequence number
          const Fw::CmdStringArg& sourceFileName, //!< The source file name
          const Fw::CmdStringArg& destFileName //!< The destination file name
      );

      //! Implementation for RemoveDirectory command handler
      //!
      void RemoveDirectory_cmdHandler(
          const FwOpcodeType opCode, //!< The opcode
          const U32 cmdSeq, //!< The command sequence number
          const Fw::CmdStringArg& dirName //!< The directory to remove
      );

      //! Implementation for ShellCommand command handler
      //!
      void ShellCommand_cmdHandler(
          const FwOpcodeType opCode, //!< The opcode
          const U32 cmdSeq, //!< The command sequence number
          const Fw::CmdStringArg& command, //!< The shell command string
          const Fw::CmdStringArg& logFileName //!< The name of the log file
      );

      //! Handler implementation for pingIn
      //!
      void pingIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U32 key /*!< Value to return to pinger*/
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Helper methdods 
      // ----------------------------------------------------------------------

      //! A system command with no arguments
      //!
      NATIVE_INT_TYPE systemCall(
          const Fw::CmdStringArg& command, //!< The command
          const Fw::CmdStringArg& logFileName //!< The log file name
      ) const;

      //! Emit telemetry based on status
      //!
      void emitTelemetry(
          const Os::FileSystem::Status status //!< The status
      );

      //! Send command response based on status
      //!
      void sendCommandResponse(
          const FwOpcodeType opCode, //!< The opcode
          const U32 cmdSeq, //!< The command sequence value
          const Os::FileSystem::Status status //!< The status
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Variables
      // ----------------------------------------------------------------------

      //! The total number of commands successfully executed
      //!
      U32 commandCount;

      //! The total number of errors
      //!
      U32 errorCount;


  };

} // end namespace Svc

#endif

// ======================================================================
// \title  ArmAppComponentImpl.hpp
// \author tcanham
// \brief  hpp file for ArmApp component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef ArmApp_HPP
#define ArmApp_HPP

#include "RobotArm/ArmApp/ArmAppComponentAc.hpp"

namespace RobotArm {

  class ArmAppComponentImpl :
    public ArmAppComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object ArmApp
      //!
      ArmAppComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object ArmApp
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object ArmApp
      //!
      ~ArmAppComponentImpl(void);

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for AA_CLAW_ANG command handler
      //! Claw angle command
      void AA_CLAW_ANG_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          F32 angle /*!< The commanded angle*/
      );

      //! Implementation for AA_BASE_ANG command handler
      //! Base angle command
      void AA_BASE_ANG_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          F32 angle /*!< The commanded angle*/
      );

      //! Implementation for AA_ARM_ANG command handler
      //! ARM angle command
      void AA_ARM_HEIGHT_ANG_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          F32 angle /*!< The commanded angle*/
      );

      //! Implementation for AA_CLAW_TILT_ANG command handler
      //! Claw tilt angle command
      void AA_ARM_LENGTH_ANG_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          F32 angle /*!< The commanded angle*/
      );

      //! Handler implementation for Run
      //!
      void Run_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          NATIVE_UINT_TYPE context /*!< The call order*/
      );

      U32 m_cycles; // cycle count



    };

} // end namespace RobotArm

#endif

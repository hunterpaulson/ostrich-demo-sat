// ======================================================================
// \title  ArmAppComponentImpl.cpp
// \author tcanham
// \brief  cpp file for ArmApp component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <RobotArm/ArmApp/ArmAppComponentImpl.hpp>
#include <RobotArm/ArmApp/ArmAppComponentImplCfg.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace RobotArm {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  ArmAppComponentImpl ::
#if FW_OBJECT_NAMES == 1
    ArmAppComponentImpl(
        const char *const compName
    ) :
      ArmAppComponentBase(compName)
#else
    ArmAppComponentImpl(void)
#endif
  {

  }

  void ArmAppComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    ArmAppComponentBase::init(queueDepth, instance);
  }

  ArmAppComponentImpl ::
    ~ArmAppComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void ArmAppComponentImpl ::
    AA_CLAW_ANG_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        F32 angle
    )
  {

      // write to motor port
      this->position_out(CLAW_PORT,angle);
      // send event
      this->log_ACTIVITY_HI_AA_ClawAngleCmd(angle);
      // send telemetry
      this->tlmWrite_AA_ClawAngle(angle);
      // return command status
      this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

  void ArmAppComponentImpl ::
    AA_BASE_ANG_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        F32 angle
    )
  {
      // write to motor port
      this->position_out(BASE_PORT,angle);
      // send event
      this->log_ACTIVITY_HI_AA_BaseAngleCmd(angle);
      // send telemetry
      this->tlmWrite_AA_BaseAngle(angle);
      // return command status
      this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

  void ArmAppComponentImpl ::
    AA_ARM_ANG_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        F32 angle
    )
  {
      // write to motor port
      this->position_out(ARM_PORT,angle);
      // send event
      this->log_ACTIVITY_HI_AA_ArmAngleCmd(angle);
      // send telemetry
      this->tlmWrite_AA_ArmAngle(angle);
      // return command status
      this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

  void ArmAppComponentImpl ::
    AA_CLAW_TILT_ANG_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        F32 angle
    )
  {
      // write to motor port
      this->position_out(CLAW_TILT_PORT,angle);
      // send event
      this->log_ACTIVITY_HI_AA_ClawTiltAngleCmd(angle);
      // send telemetry
      this->tlmWrite_AA_ClawTiltAngle(angle);
      // return command status
      this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

} // end namespace RobotArm

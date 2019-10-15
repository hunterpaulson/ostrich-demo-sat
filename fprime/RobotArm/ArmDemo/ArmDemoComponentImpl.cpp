// ======================================================================
// \title  ArmDemoComponentImpl.cpp
// \author tcanham
// \brief  cpp file for ArmDemo component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <RobotArm/ArmDemo/ArmDemoComponentImpl.hpp>
#include <RobotArm/ArmDemo/ArmDemoComponentImplCfg.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace RobotArm {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  ArmDemoComponentImpl ::
#if FW_OBJECT_NAMES == 1
    ArmDemoComponentImpl(
        const char *const compName
    ) :
      ArmDemoComponentBase(compName)
#else
    ArmDemoComponentImpl(void)
#endif
	,m_cycles(0)
  {

  }

  void ArmDemoComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    ArmDemoComponentBase::init(queueDepth, instance);
  }

  ArmDemoComponentImpl ::
    ~ArmDemoComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void ArmDemoComponentImpl ::
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

  void ArmDemoComponentImpl ::
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

  void ArmDemoComponentImpl ::
    AA_ARM_HEIGHT_ANG_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        F32 angle
    )
  {
      // write to motor port
      this->position_out(ARM_HEIGHT_PORT,angle);
      // send event
      this->log_ACTIVITY_HI_AA_ArmHeightAngleCmd(angle);
      // send telemetry
      this->tlmWrite_AA_ArmHeightAngle(angle);
      // return command status
      this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

  void ArmDemoComponentImpl ::
    AA_ARM_LENGTH_ANG_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        F32 angle
    )
  {
      // write to motor port
      this->position_out(ARM_LENGTH_PORT,angle);
      // send event
      this->log_ACTIVITY_HI_AA_ArmLengthAngleCmd(angle);
      // send telemetry
      this->tlmWrite_AA_ArmLengthAngle(angle);
      // return command status
      this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void ArmDemoComponentImpl ::
    Run_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
	  this->tlmWrite_AA_Cycles(this->m_cycles++);
  }

} // end namespace RobotArm

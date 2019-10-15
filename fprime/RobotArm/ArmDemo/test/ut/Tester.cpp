// ====================================================================== 
// \title  ArmDemo.hpp
// \author tcanham
// \brief  cpp file for ArmDemo test harness implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
// 
// ====================================================================== 

#include "Tester.hpp"

#define INSTANCE 0
#define MAX_HISTORY_SIZE 10
#define QUEUE_DEPTH 10

namespace RobotArm {

  // ----------------------------------------------------------------------
  // Construction and destruction 
  // ----------------------------------------------------------------------

  Tester ::
    Tester(void) : 
#if FW_OBJECT_NAMES == 1
      ArmDemoGTestBase("Tester", MAX_HISTORY_SIZE),
      component("ArmDemo")
#else
      ArmDemoGTestBase(MAX_HISTORY_SIZE),
      component()
#endif
  {
    this->initComponents();
    this->connectPorts();
  }

  Tester ::
    ~Tester(void) 
  {
    
  }

  // ----------------------------------------------------------------------
  // Tests 
  // ----------------------------------------------------------------------

  void Tester ::
    testCycle(void)
  {
	  static const U32 testIters = 50;

	  for (U32 cycle = 0; cycle < testIters; cycle++) {
		  // clear logs
		  this->clearHistory();
		  // verify ticks are zero - white box test
		  ASSERT_EQ(this->component.m_cycles,cycle);
		  // send scheduler tick
		  this->invoke_to_Run(0, 0);
		  // since the component is active, dispatch message
		  this->component.doDispatch();
		  // check component stored cycle value
		  ASSERT_EQ(this->component.m_cycles,cycle+1);
		  // check telemetry channel
		  ASSERT_TLM_SIZE(1);
		  ASSERT_TLM_AA_Cycles_SIZE(1);
		  ASSERT_TLM_AA_Cycles(0,cycle);
	  }
  }

  void Tester::testAngles(void) {

	  static const F32 angles[] = {-90.0, 0.0, 90.0};

	  for (U32 index = 0; index < FW_NUM_ARRAY_ELEMENTS(angles); index++) {
		  // clear history for each angle tested
		  this->clearHistory();

		  // send command to change claw angle
		  this->sendCmd_AA_CLAW_ANG(0,10,angles[index]);
		  // dispatch command
		  this->component.doDispatch();

		  // verify output port call

		  // verify only one port call was made
		  ASSERT_FROM_PORT_HISTORY_SIZE(1);
		  // verify the correct port was called
		  ASSERT_from_position_SIZE(1);
		  // verify the value was sent to the correct port index
		  ASSERT_from_position(0,angles[index]);

		  // verify telemetry was sent

		  // verify only one channel was written
		  ASSERT_TLM_SIZE(1);
		  // verify that the correct channel was written
		  ASSERT_TLM_AA_ClawAngle_SIZE(1);
		  // verify correct value was written
		  ASSERT_TLM_AA_ClawAngle(0,angles[index]);

		  // verify event was sent

		  // verify only one event was sent
		  ASSERT_EVENTS_SIZE(1);
		  // verify the correct event was sent
		  ASSERT_EVENTS_AA_ClawAngleCmd_SIZE(1);
		  // verify the correct values were sent
		  ASSERT_EVENTS_AA_ClawAngleCmd(0,angles[index]);

		  // verify the command response was sent
		  ASSERT_CMD_RESPONSE_SIZE(1);
		  ASSERT_CMD_RESPONSE(0,ArmDemoComponentBase::OPCODE_AA_CLAW_ANG,10,Fw::COMMAND_OK);

		  // clear history
		  this->clearHistory();


		  // send command to change base angle
		  this->sendCmd_AA_BASE_ANG(0,10,angles[index]);
		  // dispatch command
		  this->component.doDispatch();

		  // verify output port call

		  // verify only one port call was made
		  ASSERT_FROM_PORT_HISTORY_SIZE(1);
		  // verify the correct port was called
		  ASSERT_from_position_SIZE(1);
		  // verify the value was sent
		  ASSERT_from_position(0,angles[index]);

		  // verify telemetry was sent

		  // verify only one channel was written
		  ASSERT_TLM_SIZE(1);
		  // verify that the correct channel was written
		  ASSERT_TLM_AA_BaseAngle_SIZE(1);
		  // verify correct value was written
		  ASSERT_TLM_AA_BaseAngle(0,angles[index]);

		  // verify event was sent

		  // verify only one event was sent
		  ASSERT_EVENTS_SIZE(1);
		  // verify the correct event was sent
		  ASSERT_EVENTS_AA_BaseAngleCmd_SIZE(1);
		  // verify the correct values were sent
		  ASSERT_EVENTS_AA_BaseAngleCmd(0,angles[index]);

		  // verify the command response was sent
		  ASSERT_CMD_RESPONSE_SIZE(1);
		  ASSERT_CMD_RESPONSE(0,ArmDemoComponentBase::OPCODE_AA_BASE_ANG,10,Fw::COMMAND_OK);

		  // clear history
		  this->clearHistory();

		  // send command to change base angle
		  this->sendCmd_AA_ARM_HEIGHT_ANG(0,10,angles[index]);
		  // dispatch command
		  this->component.doDispatch();

		  // verify output port call

		  // verify only one port call was made
		  ASSERT_FROM_PORT_HISTORY_SIZE(1);
		  // verify the correct port was called
		  ASSERT_from_position_SIZE(1);
		  // verify the value was sent
		  ASSERT_from_position(0,angles[index]);

		  // verify telemetry was sent

		  // verify only one channel was written
		  ASSERT_TLM_SIZE(1);
		  // verify that the correct channel was written
		  ASSERT_TLM_AA_ArmHeightAngle_SIZE(1);
		  // verify correct value was written
		  ASSERT_TLM_AA_ArmHeightAngle(0,angles[index]);

		  // verify event was sent

		  // verify only one event was sent
		  ASSERT_EVENTS_SIZE(1);
		  // verify the correct event was sent
		  ASSERT_EVENTS_AA_ArmHeightAngleCmd_SIZE(1);
		  // verify the correct values were sent
		  ASSERT_EVENTS_AA_ArmHeightAngleCmd(0,angles[index]);

		  // verify the command response was sent
		  ASSERT_CMD_RESPONSE_SIZE(1);
		  ASSERT_CMD_RESPONSE(0,ArmDemoComponentBase::OPCODE_AA_ARM_HEIGHT_ANG,10,Fw::COMMAND_OK);

		  // clear history
		  this->clearHistory();

		  // send command to change base angle
		  this->sendCmd_AA_ARM_LENGTH_ANG(0,10,angles[index]);
		  // dispatch command
		  this->component.doDispatch();

		  // verify output port call

		  // verify only one port call was made
		  ASSERT_FROM_PORT_HISTORY_SIZE(1);
		  // verify the correct port was called
		  ASSERT_from_position_SIZE(1);
		  // verify the value was sent
		  ASSERT_from_position(0,angles[index]);

		  // verify telemetry was sent

		  // verify only one channel was written
		  ASSERT_TLM_SIZE(1);
		  // verify that the correct channel was written
		  ASSERT_TLM_AA_ArmLengthAngle_SIZE(1);
		  // verify correct value was written
		  ASSERT_TLM_AA_ArmLengthAngle(0,angles[index]);

		  // verify event was sent

		  // verify only one event was sent
		  ASSERT_EVENTS_SIZE(1);
		  // verify the correct event was sent
		  ASSERT_EVENTS_AA_ArmLengthAngleCmd_SIZE(1);
		  // verify the correct values were sent
		  ASSERT_EVENTS_AA_ArmLengthAngleCmd(0,angles[index]);

		  // verify the command response was sent
		  ASSERT_CMD_RESPONSE_SIZE(1);
		  ASSERT_CMD_RESPONSE(0,ArmDemoComponentBase::OPCODE_AA_ARM_LENGTH_ANG,10,Fw::COMMAND_OK);

	  }

  }

  // ----------------------------------------------------------------------
  // Handlers for typed from ports
  // ----------------------------------------------------------------------

  void Tester ::
    from_position_handler(
        const NATIVE_INT_TYPE portNum,
        F32 angle
    )
  {
    this->pushFromPortEntry_position(angle);
  }

  // ----------------------------------------------------------------------
  // Helper methods 
  // ----------------------------------------------------------------------

  void Tester ::
    connectPorts(void) 
  {

    // Run
    this->connect_to_Run(
        0,
        this->component.get_Run_InputPort(0)
    );

    // CmdDisp
    this->connect_to_CmdDisp(
        0,
        this->component.get_CmdDisp_InputPort(0)
    );

    // position
    for (NATIVE_INT_TYPE i = 0; i < 4; ++i) {
      this->component.set_position_OutputPort(
          i, 
          this->get_from_position(i)
      );
    }

    // CmdStatus
    this->component.set_CmdStatus_OutputPort(
        0, 
        this->get_from_CmdStatus(0)
    );

    // CmdReg
    this->component.set_CmdReg_OutputPort(
        0, 
        this->get_from_CmdReg(0)
    );

    // Tlm
    this->component.set_Tlm_OutputPort(
        0, 
        this->get_from_Tlm(0)
    );

    // Time
    this->component.set_Time_OutputPort(
        0, 
        this->get_from_Time(0)
    );

    // Log
    this->component.set_Log_OutputPort(
        0, 
        this->get_from_Log(0)
    );

    // LogText
    this->component.set_LogText_OutputPort(
        0, 
        this->get_from_LogText(0)
    );




  }

  void Tester ::
    initComponents(void) 
  {
    this->init();
    this->component.init(
        QUEUE_DEPTH, INSTANCE
    );
  }

} // end namespace RobotArm

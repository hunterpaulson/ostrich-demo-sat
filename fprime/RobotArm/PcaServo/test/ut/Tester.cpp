// ====================================================================== 
// \title  PcaServo.hpp
// \author tcanham
// \brief  cpp file for PcaServo test harness implementation class
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
      PcaServoGTestBase("Tester", MAX_HISTORY_SIZE),
      component("PcaServo")
#else
      PcaServoGTestBase(MAX_HISTORY_SIZE),
      component()
#endif
	  ,m_i2cIndex(0)
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

  void Tester::servoTest(void)
  {
	  static const F32 angles[] = {-90.0, 0.0, 90.0};

	  // set configuration parameters
	  this->component.configure(0,0x40);

	  for (U32 index = 0; index < FW_NUM_ARRAY_ELEMENTS(angles); index++) {
		  // clear history for each angle tested
		  this->clearHistory();
		  // set expected I2c buffers
		  this->m_i2cIndex = 0;

		  this->m_i2cBuffSizes[0] = 2;
		  this->m_i2cBuff[0][0] = 0x6;
		  this->m_i2cBuff[0][1] = 0x0;

		  // borrowed from component code
		  U16 reg = MINUS_90 + (PLUS_90 - MINUS_90)*((90.0+angles[index])/180.0);

		  this->m_i2cBuffSizes[1] = 3;
		  this->m_i2cBuff[1][0] = 0x8;
		  this->m_i2cBuff[1][1] = reg & 0xFF;
		  this->m_i2cBuff[1][2] = (reg >> 8) & 0xFF;

		  // send port call
		  this->invoke_to_position(0,angles[index]);
		  // dispatch message
		  this->component.doDispatch();
		  // verify port calls

		  // verify the correct number of port calls was made
		  ASSERT_FROM_PORT_HISTORY_SIZE(2);
		  // verify the correct port was called
		  ASSERT_from_i2c_SIZE(2);
		  // first port call sets zero point of servo
		  // Build buffer

		  // First buffer has two bytes
		  Fw::Buffer i2cBuff(0,0,(U64)this->component.m_data,2);
		  ASSERT_from_i2c(0,(U32)0x40,i2cBuff);
		  // Second buffer has three bytes to set duty cycle
		  i2cBuff.setsize(3);
		  ASSERT_from_i2c(1,(U32)0x40,i2cBuff);

//		  // clear history
//		  this->clearHistory();
//		  // send command
//		  this->sendCmd_PS_ANG(0,10,angles[index]);
//		  // dispatch message
//		  this->component.doDispatch();
//		  // verify port calls
//		  ASSERT_FROM_PORT_HISTORY_SIZE(2);

	  }

  }

  void Tester::enableTest(void)
  {
	  // set configuration parameters
	  this->component.configure(0,0x40);

	  // set expected I2c buffers
	  this->m_i2cIndex = 0;

	  this->m_i2cBuffSizes[0] = 2;
	  this->m_i2cBuff[0][0] = 0x0;
	  this->m_i2cBuff[0][1] = 0x20;

	  this->m_i2cBuffSizes[1] = 2;
	  this->m_i2cBuff[1][0] = 0x0;
	  this->m_i2cBuff[1][1] = 0x10;

	  this->m_i2cBuffSizes[2] = 2;
	  this->m_i2cBuff[2][0] = 0xfe;
	  this->m_i2cBuff[2][1] = 0x79;

	  this->m_i2cBuffSizes[3] = 2;
	  this->m_i2cBuff[3][0] = 0x0;
	  this->m_i2cBuff[3][1] = 0x20;

	  this->m_i2cBuffSizes[4] = 2;
	  this->m_i2cBuff[4][0] = 0xfe;
	  this->m_i2cBuff[4][1] = 0x1e;

	  // send enable command
	  this->sendCmd_PS_EN(0,10);
	  // dispatch message
	  this->component.doDispatch();
  }

  void Tester::disableTest(void)
  {
	  // set configuration parameters
	  this->component.configure(0,0x40);

	  // set expected I2c buffers
	  this->m_i2cIndex = 0;

	  this->m_i2cBuffSizes[0] = 2;
	  this->m_i2cBuff[0][0] = 0x0;
	  this->m_i2cBuff[0][1] = 0x10;

	  // send enable command
	  this->sendCmd_PS_DIS(0,10);
	  // dispatch message
	  this->component.doDispatch();
  }

  // ----------------------------------------------------------------------
  // Handlers for typed from ports
  // ----------------------------------------------------------------------

  void Tester ::
    from_i2c_handler(
        const NATIVE_INT_TYPE portNum,
        U32 addr,
        Fw::Buffer &serBuffer
    )
  {

    this->pushFromPortEntry_i2c(addr, serBuffer);
    U8* ptr = (U8*) serBuffer.getdata();

    // compare data to expected
    for (U32 byte = 0; byte < this->m_i2cBuffSizes[this->m_i2cIndex]; byte++) {
    	ASSERT_EQ(ptr[byte],this->m_i2cBuff[this->m_i2cIndex][byte]);
    }

    this->m_i2cIndex++;
  }

  // ----------------------------------------------------------------------
  // Helper methods 
  // ----------------------------------------------------------------------

  void Tester ::
    connectPorts(void) 
  {

    // position
    this->connect_to_position(
        0,
        this->component.get_position_InputPort(0)
    );

    // CmdDisp
    this->connect_to_CmdDisp(
        0,
        this->component.get_CmdDisp_InputPort(0)
    );

    // i2c
    this->component.set_i2c_OutputPort(
        0, 
        this->get_from_i2c(0)
    );

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

  void Tester::textLogIn(const FwEventIdType id, //!< The event ID
          Fw::Time& timeTag, //!< The time
          const Fw::TextLogSeverity severity, //!< The severity
          const Fw::TextLogString& text //!< The event string
          ) {
      TextLogEntry e = { id, timeTag, severity, text };

      printTextLogHistoryEntry(e, stdout);
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

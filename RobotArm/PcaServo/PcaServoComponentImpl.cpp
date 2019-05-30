// ======================================================================
// \title  PcaServoComponentImpl.cpp
// \author tcanham
// \brief  cpp file for PcaServo component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <RobotArm/PcaServo/PcaServoComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace RobotArm {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  PcaServoComponentImpl ::
#if FW_OBJECT_NAMES == 1
    PcaServoComponentImpl(
        const char *const compName
    ) :
      PcaServoComponentBase(compName)
#else
    PcaServoComponentImpl(void)
#endif
	 ,m_instance(0), m_addr(0)
  {
	  this->m_buff.setdata((U64)this->m_data);
	  this->m_buff.setsize(I2C_BUFFER_SIZE);
  }

  void PcaServoComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    PcaServoComponentBase::init(queueDepth, instance);
  }

  PcaServoComponentImpl ::
    ~PcaServoComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void PcaServoComponentImpl ::
    position_handler(
        const NATIVE_INT_TYPE portNum,
        F32 angle
    )
  {
	  // call common handler
	  this->setPos(angle);
  }

  void PcaServoComponentImpl ::
    PS_ANG_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        F32 angle
    )
  {
	  // call common handler
	  this->setPos(angle);
	  // return command status
	  this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }


  void PcaServoComponentImpl::setPos(F32 angle) {

	  // See https://www.nxp.com/docs/en/data-sheet/PCA9685.pdf and
	  // https://learn.sparkfun.com/tutorials/pi-servo-hat-hookup-guide#software---python
	  // for scaling

	  // set zero point. Pick the register set for this servo
	  this->m_data[0] = 0x6 + 4*this->m_instance;
	  this->m_data[1] = 0;
	  this->m_buff.setsize(2);
	  // call I2C port
	  this->i2c_out(0,SERVO_BRD_ADDR,this->m_buff);

	  // compute the PWM duty cycle for angle
	  U16 reg = MINUS_90 + (PLUS_90 - MINUS_90)*((90.0+angle)/180.0);
	  // put values in I2c buffer
	  this->m_data[0] = 0x8 + 4*this->m_instance;
	  this->m_data[1] = reg & 0xFF;
	  this->m_data[2] = (reg >> 8) & 0xFF;
	  this->m_buff.setsize(3);
	  // call I2C port
	  this->i2c_out(0,SERVO_BRD_ADDR,this->m_buff);

	  // send event
	  this->log_ACTIVITY_HI_PS_AngleCmd(this->m_instance,angle,reg);
	  // send telemetry
	  this->tlmWrite_PS_Angle(angle);
	  this->tlmWrite_PS_Reg(reg);

  }


  void PcaServoComponentImpl::configure(
		  U32 instance,  //!< servo instance on board
		  U32 addr //!< servo board address
		  ) {
	  this->m_instance = instance;
	  this->m_addr = addr;
  }

  void PcaServoComponentImpl::configChip(void) {

	  // enable chip
	  this->m_data[0] = 0;
	  this->m_data[1] = 0x20; //!< enable PWM
	  this->m_buff.setsize(2);
	  // call I2C port
	  this->i2c_out(0,SERVO_BRD_ADDR,this->m_buff);

	  // enable prescale setting
	  this->m_data[0] = 0;
	  this->m_data[1] = 0x10; //!< enable PWM
	  this->m_buff.setsize(2);
	  // call I2C port
	  this->i2c_out(0,SERVO_BRD_ADDR,this->m_buff);

	  // set prescale value
	  this->m_data[0] = 0xfe;
	  this->m_data[1] = 0x79; //!< enable PWM
	  this->m_buff.setsize(2);
	  // call I2C port
	  this->i2c_out(0,SERVO_BRD_ADDR,this->m_buff);

	  // enable multi-byte
	  this->m_data[0] = 0xfe;
	  this->m_data[1] = 0x1e; //!< enable multi-byte
	  this->m_buff.setsize(2);
	  // call I2C port
	  this->i2c_out(0,SERVO_BRD_ADDR,this->m_buff);

  }



} // end namespace RobotArm

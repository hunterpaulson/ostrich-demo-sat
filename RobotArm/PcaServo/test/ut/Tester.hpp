// ======================================================================
// \title  PcaServo/test/ut/Tester.hpp
// \author tcanham
// \brief  hpp file for PcaServo test harness implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef TESTER_HPP
#define TESTER_HPP

#include "GTestBase.hpp"
#include "RobotArm/PcaServo/PcaServoComponentImpl.hpp"

namespace RobotArm {

  class Tester :
    public PcaServoGTestBase
  {

      // ----------------------------------------------------------------------
      // Construction and destruction
      // ----------------------------------------------------------------------

    public:

      //! Construct object Tester
      //!
      Tester(void);

      //! Destroy object Tester
      //!
      ~Tester(void);

    public:

      // ----------------------------------------------------------------------
      // Tests
      // ----------------------------------------------------------------------

      //! servo output test
      //!
      void servoTest(void);
      void enableTest(void);
      void disableTest(void);

    private:

      // ----------------------------------------------------------------------
      // Handlers for typed from ports
      // ----------------------------------------------------------------------

      //! Handler for from_i2c
      //!
      void from_i2c_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U32 addr, 
          Fw::Buffer &serBuffer 
      );

    private:

      // ----------------------------------------------------------------------
      // Helper methods
      // ----------------------------------------------------------------------

      //! Connect ports
      //!
      void connectPorts(void);

      //! Initialize components
      //!
      void initComponents(void);

    private:

      void textLogIn(
                const FwEventIdType id, //!< The event ID
                Fw::Time& timeTag, //!< The time
                const Fw::TextLogSeverity severity, //!< The severity
                const Fw::TextLogString& text //!< The event string
            );


      // ----------------------------------------------------------------------
      // Variables
      // ----------------------------------------------------------------------

      //! The component under test
      //!
      PcaServoComponentImpl component;

      // data buffers to verify I2C commands
	  U8 m_i2cBuff[5][I2C_BUFFER_SIZE];
	  U32 m_i2cBuffSizes[5];
	  // index into i2c calls
	  NATIVE_INT_TYPE m_i2cIndex;


  };

} // end namespace RobotArm

#endif

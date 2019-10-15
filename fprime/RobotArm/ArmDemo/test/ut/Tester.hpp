// ======================================================================
// \title  ArmDemo/test/ut/Tester.hpp
// \author tcanham
// \brief  hpp file for ArmDemo test harness implementation class
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
#include "RobotArm/ArmDemo/ArmDemoComponentImpl.hpp"

namespace RobotArm {

  class Tester :
    public ArmDemoGTestBase
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

      //! Test cycling
      //!
      void testCycle(void);

      //! Test claw angle
      //!
      void testAngles(void);

    private:

      // ----------------------------------------------------------------------
      // Handlers for typed from ports
      // ----------------------------------------------------------------------

      //! Handler for from_position
      //!
      void from_position_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 angle 
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

      // ----------------------------------------------------------------------
      // Variables
      // ----------------------------------------------------------------------

      //! The component under test
      //!
      ArmDemoComponentImpl component;

  };

} // end namespace RobotArm

#endif

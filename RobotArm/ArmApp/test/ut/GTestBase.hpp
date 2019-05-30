// ======================================================================
// \title  ArmApp/test/ut/GTestBase.hpp
// \author Auto-generated
// \brief  hpp file for ArmApp component Google Test harness base class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef ArmApp_GTEST_BASE_HPP
#define ArmApp_GTEST_BASE_HPP

#include "TesterBase.hpp"
#include "gtest/gtest.h"

// ----------------------------------------------------------------------
// Macros for command history assertions
// ----------------------------------------------------------------------

#define ASSERT_CMD_RESPONSE_SIZE(size) \
  this->assertCmdResponse_size(__FILE__, __LINE__, size)

#define ASSERT_CMD_RESPONSE(index, opCode, cmdSeq, response) \
  this->assertCmdResponse(__FILE__, __LINE__, index, opCode, cmdSeq, response)

// ----------------------------------------------------------------------
// Macros for telemetry history assertions
// ----------------------------------------------------------------------

#define ASSERT_TLM_SIZE(size) \
  this->assertTlm_size(__FILE__, __LINE__, size)

#define ASSERT_TLM_AA_ClawAngle_SIZE(size) \
  this->assertTlm_AA_ClawAngle_size(__FILE__, __LINE__, size)

#define ASSERT_TLM_AA_ClawAngle(index, value) \
  this->assertTlm_AA_ClawAngle(__FILE__, __LINE__, index, value)

#define ASSERT_TLM_AA_BaseAngle_SIZE(size) \
  this->assertTlm_AA_BaseAngle_size(__FILE__, __LINE__, size)

#define ASSERT_TLM_AA_BaseAngle(index, value) \
  this->assertTlm_AA_BaseAngle(__FILE__, __LINE__, index, value)

#define ASSERT_TLM_AA_ArmAngle_SIZE(size) \
  this->assertTlm_AA_ArmAngle_size(__FILE__, __LINE__, size)

#define ASSERT_TLM_AA_ArmAngle(index, value) \
  this->assertTlm_AA_ArmAngle(__FILE__, __LINE__, index, value)

#define ASSERT_TLM_AA_ClawTiltAngle_SIZE(size) \
  this->assertTlm_AA_ClawTiltAngle_size(__FILE__, __LINE__, size)

#define ASSERT_TLM_AA_ClawTiltAngle(index, value) \
  this->assertTlm_AA_ClawTiltAngle(__FILE__, __LINE__, index, value)

// ----------------------------------------------------------------------
// Macros for event history assertions
// ----------------------------------------------------------------------

#define ASSERT_EVENTS_SIZE(size) \
  this->assertEvents_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_AA_ClawAngleCmd_SIZE(size) \
  this->assertEvents_AA_ClawAngleCmd_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_AA_ClawAngleCmd(index, _angle) \
  this->assertEvents_AA_ClawAngleCmd(__FILE__, __LINE__, index, _angle)

#define ASSERT_EVENTS_AA_BaseAngleCmd_SIZE(size) \
  this->assertEvents_AA_BaseAngleCmd_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_AA_BaseAngleCmd(index, _angle) \
  this->assertEvents_AA_BaseAngleCmd(__FILE__, __LINE__, index, _angle)

#define ASSERT_EVENTS_AA_ArmAngleCmd_SIZE(size) \
  this->assertEvents_AA_ArmAngleCmd_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_AA_ArmAngleCmd(index, _angle) \
  this->assertEvents_AA_ArmAngleCmd(__FILE__, __LINE__, index, _angle)

#define ASSERT_EVENTS_AA_ClawTiltAngleCmd_SIZE(size) \
  this->assertEvents_AA_ClawTiltAngleCmd_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_AA_ClawTiltAngleCmd(index, _angle) \
  this->assertEvents_AA_ClawTiltAngleCmd(__FILE__, __LINE__, index, _angle)

// ----------------------------------------------------------------------
// Macros for typed user from port history assertions
// ----------------------------------------------------------------------

#define ASSERT_FROM_PORT_HISTORY_SIZE(size) \
  this->assertFromPortHistory_size(__FILE__, __LINE__, size)

#define ASSERT_from_position_SIZE(size) \
  this->assert_from_position_size(__FILE__, __LINE__, size)

#define ASSERT_from_position(index, _angle) \
  { \
    ASSERT_GT(this->fromPortHistory_position->size(), static_cast<U32>(index)) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Index into history of from_position\n" \
    << "  Expected: Less than size of history (" \
    << this->fromPortHistory_position->size() << ")\n" \
    << "  Actual:   " << index << "\n"; \
    const FromPortEntry_position& _e = \
      this->fromPortHistory_position->at(index); \
    ASSERT_EQ(_angle, _e.angle) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Value of argument angle at index " \
    << index \
    << " in history of from_position\n" \
    << "  Expected: " << _angle << "\n" \
    << "  Actual:   " << _e.angle << "\n"; \
  }

namespace RobotArm {

  //! \class ArmAppGTestBase
  //! \brief Auto-generated base class for ArmApp component Google Test harness
  //!
  class ArmAppGTestBase :
    public ArmAppTesterBase
  {

    protected:

      // ----------------------------------------------------------------------
      // Construction and destruction
      // ----------------------------------------------------------------------

      //! Construct object ArmAppGTestBase
      //!
      ArmAppGTestBase(
#if FW_OBJECT_NAMES == 1
          const char *const compName, /*!< The component name*/
          const U32 maxHistorySize /*!< The maximum size of each history*/
#else
          const U32 maxHistorySize /*!< The maximum size of each history*/
#endif
      );

      //! Destroy object ArmAppGTestBase
      //!
      virtual ~ArmAppGTestBase(void);

    protected:

      // ----------------------------------------------------------------------
      // Commands
      // ----------------------------------------------------------------------

      //! Assert size of command response history
      //!
      void assertCmdResponse_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      //! Assert command response in history at index
      //!
      void assertCmdResponse(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          const Fw::CommandResponse response /*!< The command response*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Telemetry
      // ----------------------------------------------------------------------

      //! Assert size of telemetry history
      //!
      void assertTlm_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Channel: AA_ClawAngle
      // ----------------------------------------------------------------------

      //! Assert telemetry value in history at index
      //!
      void assertTlm_AA_ClawAngle_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertTlm_AA_ClawAngle(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const F32& val /*!< The channel value*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Channel: AA_BaseAngle
      // ----------------------------------------------------------------------

      //! Assert telemetry value in history at index
      //!
      void assertTlm_AA_BaseAngle_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertTlm_AA_BaseAngle(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const F32& val /*!< The channel value*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Channel: AA_ArmAngle
      // ----------------------------------------------------------------------

      //! Assert telemetry value in history at index
      //!
      void assertTlm_AA_ArmAngle_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertTlm_AA_ArmAngle(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const F32& val /*!< The channel value*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Channel: AA_ClawTiltAngle
      // ----------------------------------------------------------------------

      //! Assert telemetry value in history at index
      //!
      void assertTlm_AA_ClawTiltAngle_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertTlm_AA_ClawTiltAngle(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const F32& val /*!< The channel value*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Events
      // ----------------------------------------------------------------------

      void assertEvents_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: AA_ClawAngleCmd
      // ----------------------------------------------------------------------

      void assertEvents_AA_ClawAngleCmd_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_AA_ClawAngleCmd(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const F32 angle /*!< The commanded angle*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: AA_BaseAngleCmd
      // ----------------------------------------------------------------------

      void assertEvents_AA_BaseAngleCmd_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_AA_BaseAngleCmd(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const F32 angle /*!< The commanded angle*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: AA_ArmAngleCmd
      // ----------------------------------------------------------------------

      void assertEvents_AA_ArmAngleCmd_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_AA_ArmAngleCmd(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const F32 angle /*!< The commanded angle*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: AA_ClawTiltAngleCmd
      // ----------------------------------------------------------------------

      void assertEvents_AA_ClawTiltAngleCmd_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_AA_ClawTiltAngleCmd(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const F32 angle /*!< The commanded angle*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // From ports
      // ----------------------------------------------------------------------

      void assertFromPortHistory_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // From port: position
      // ----------------------------------------------------------------------

      void assert_from_position_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

  };

} // end namespace RobotArm

#endif

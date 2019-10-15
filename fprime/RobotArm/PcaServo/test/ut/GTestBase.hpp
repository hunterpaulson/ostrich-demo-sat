// ======================================================================
// \title  PcaServo/test/ut/GTestBase.hpp
// \author Auto-generated
// \brief  hpp file for PcaServo component Google Test harness base class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef PcaServo_GTEST_BASE_HPP
#define PcaServo_GTEST_BASE_HPP

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

#define ASSERT_TLM_PS_Angle_SIZE(size) \
  this->assertTlm_PS_Angle_size(__FILE__, __LINE__, size)

#define ASSERT_TLM_PS_Angle(index, value) \
  this->assertTlm_PS_Angle(__FILE__, __LINE__, index, value)

#define ASSERT_TLM_PS_Reg_SIZE(size) \
  this->assertTlm_PS_Reg_size(__FILE__, __LINE__, size)

#define ASSERT_TLM_PS_Reg(index, value) \
  this->assertTlm_PS_Reg(__FILE__, __LINE__, index, value)

// ----------------------------------------------------------------------
// Macros for event history assertions
// ----------------------------------------------------------------------

#define ASSERT_EVENTS_SIZE(size) \
  this->assertEvents_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_PS_AngleCmd_SIZE(size) \
  this->assertEvents_PS_AngleCmd_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_PS_AngleCmd(index, _inst, _angle, _reg) \
  this->assertEvents_PS_AngleCmd(__FILE__, __LINE__, index, _inst, _angle, _reg)

// ----------------------------------------------------------------------
// Macros for typed user from port history assertions
// ----------------------------------------------------------------------

#define ASSERT_FROM_PORT_HISTORY_SIZE(size) \
  this->assertFromPortHistory_size(__FILE__, __LINE__, size)

#define ASSERT_from_i2c_SIZE(size) \
  this->assert_from_i2c_size(__FILE__, __LINE__, size)

#define ASSERT_from_i2c(index, _addr, _serBuffer) \
  { \
    ASSERT_GT(this->fromPortHistory_i2c->size(), static_cast<U32>(index)) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Index into history of from_i2c\n" \
    << "  Expected: Less than size of history (" \
    << this->fromPortHistory_i2c->size() << ")\n" \
    << "  Actual:   " << index << "\n"; \
    const FromPortEntry_i2c& _e = \
      this->fromPortHistory_i2c->at(index); \
    ASSERT_EQ(_addr, _e.addr) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Value of argument addr at index " \
    << index \
    << " in history of from_i2c\n" \
    << "  Expected: " << _addr << "\n" \
    << "  Actual:   " << _e.addr << "\n"; \
    ASSERT_EQ(_serBuffer, _e.serBuffer) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Value of argument serBuffer at index " \
    << index \
    << " in history of from_i2c\n" \
    << "  Expected: " << _serBuffer << "\n" \
    << "  Actual:   " << _e.serBuffer << "\n"; \
  }

namespace RobotArm {

  //! \class PcaServoGTestBase
  //! \brief Auto-generated base class for PcaServo component Google Test harness
  //!
  class PcaServoGTestBase :
    public PcaServoTesterBase
  {

    protected:

      // ----------------------------------------------------------------------
      // Construction and destruction
      // ----------------------------------------------------------------------

      //! Construct object PcaServoGTestBase
      //!
      PcaServoGTestBase(
#if FW_OBJECT_NAMES == 1
          const char *const compName, /*!< The component name*/
          const U32 maxHistorySize /*!< The maximum size of each history*/
#else
          const U32 maxHistorySize /*!< The maximum size of each history*/
#endif
      );

      //! Destroy object PcaServoGTestBase
      //!
      virtual ~PcaServoGTestBase(void);

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
      // Channel: PS_Angle
      // ----------------------------------------------------------------------

      //! Assert telemetry value in history at index
      //!
      void assertTlm_PS_Angle_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertTlm_PS_Angle(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const F32& val /*!< The channel value*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Channel: PS_Reg
      // ----------------------------------------------------------------------

      //! Assert telemetry value in history at index
      //!
      void assertTlm_PS_Reg_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertTlm_PS_Reg(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const U16& val /*!< The channel value*/
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
      // Event: PS_AngleCmd
      // ----------------------------------------------------------------------

      void assertEvents_PS_AngleCmd_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_PS_AngleCmd(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 __index, /*!< The index*/
          const U8 inst, /*!< The motor instance*/
          const F32 angle, /*!< The commanded angle*/
          const U16 reg /*!< The register value*/
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
      // From port: i2c
      // ----------------------------------------------------------------------

      void assert_from_i2c_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

  };

} // end namespace RobotArm

#endif

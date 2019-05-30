// ======================================================================
// \title  ArmApp/test/ut/GTestBase.cpp
// \author Auto-generated
// \brief  cpp file for ArmApp component Google Test harness base class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#include "GTestBase.hpp"

namespace RobotArm {

  // ----------------------------------------------------------------------
  // Construction and destruction
  // ----------------------------------------------------------------------

  ArmAppGTestBase ::
    ArmAppGTestBase(
#if FW_OBJECT_NAMES == 1
        const char *const compName,
        const U32 maxHistorySize
#else
        const U32 maxHistorySize
#endif
    ) :
        ArmAppTesterBase (
#if FW_OBJECT_NAMES == 1
            compName,
#endif
            maxHistorySize
        )
  {

  }

  ArmAppGTestBase ::
    ~ArmAppGTestBase(void)
  {

  }

  // ----------------------------------------------------------------------
  // Commands
  // ----------------------------------------------------------------------

  void ArmAppGTestBase ::
    assertCmdResponse_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ((unsigned long) size, this->cmdResponseHistory->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of command response history\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->cmdResponseHistory->size() << "\n";
  }

  void ArmAppGTestBase ::
    assertCmdResponse(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        const Fw::CommandResponse response
    )
    const
  {
    ASSERT_LT(__index, this->cmdResponseHistory->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into command response history\n"
      << "  Expected: Less than size of command response history ("
      << this->cmdResponseHistory->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const CmdResponse& e = this->cmdResponseHistory->at(__index);
    ASSERT_EQ(opCode, e.opCode)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Opcode at index "
      << __index
      << " in command response history\n"
      << "  Expected: " << opCode << "\n"
      << "  Actual:   " << e.opCode << "\n";
    ASSERT_EQ(cmdSeq, e.cmdSeq)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Command sequence number at index "
      << __index
      << " in command response history\n"
      << "  Expected: " << cmdSeq << "\n"
      << "  Actual:   " << e.cmdSeq << "\n";
    ASSERT_EQ(response, e.response)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Command response at index "
      << __index
      << " in command response history\n"
      << "  Expected: " << response << "\n"
      << "  Actual:   " << e.response << "\n";
  }

  // ----------------------------------------------------------------------
  // Telemetry
  // ----------------------------------------------------------------------

  void ArmAppGTestBase ::
    assertTlm_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->tlmSize)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Total size of all telemetry histories\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmSize << "\n";
  }

  // ----------------------------------------------------------------------
  // Channel: AA_ClawAngle
  // ----------------------------------------------------------------------

  void ArmAppGTestBase ::
    assertTlm_AA_ClawAngle_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(this->tlmHistory_AA_ClawAngle->size(), size)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for telemetry channel AA_ClawAngle\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmHistory_AA_ClawAngle->size() << "\n";
  }

  void ArmAppGTestBase ::
    assertTlm_AA_ClawAngle(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const F32& val
    )
    const
  {
    ASSERT_LT(__index, this->tlmHistory_AA_ClawAngle->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of telemetry channel AA_ClawAngle\n"
      << "  Expected: Less than size of history ("
      << this->tlmHistory_AA_ClawAngle->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const TlmEntry_AA_ClawAngle& e =
      this->tlmHistory_AA_ClawAngle->at(__index);
    ASSERT_EQ(val, e.arg)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value at index "
      << __index
      << " on telmetry channel AA_ClawAngle\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.arg << "\n";
  }

  // ----------------------------------------------------------------------
  // Channel: AA_BaseAngle
  // ----------------------------------------------------------------------

  void ArmAppGTestBase ::
    assertTlm_AA_BaseAngle_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(this->tlmHistory_AA_BaseAngle->size(), size)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for telemetry channel AA_BaseAngle\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmHistory_AA_BaseAngle->size() << "\n";
  }

  void ArmAppGTestBase ::
    assertTlm_AA_BaseAngle(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const F32& val
    )
    const
  {
    ASSERT_LT(__index, this->tlmHistory_AA_BaseAngle->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of telemetry channel AA_BaseAngle\n"
      << "  Expected: Less than size of history ("
      << this->tlmHistory_AA_BaseAngle->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const TlmEntry_AA_BaseAngle& e =
      this->tlmHistory_AA_BaseAngle->at(__index);
    ASSERT_EQ(val, e.arg)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value at index "
      << __index
      << " on telmetry channel AA_BaseAngle\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.arg << "\n";
  }

  // ----------------------------------------------------------------------
  // Channel: AA_ArmAngle
  // ----------------------------------------------------------------------

  void ArmAppGTestBase ::
    assertTlm_AA_ArmAngle_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(this->tlmHistory_AA_ArmAngle->size(), size)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for telemetry channel AA_ArmAngle\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmHistory_AA_ArmAngle->size() << "\n";
  }

  void ArmAppGTestBase ::
    assertTlm_AA_ArmAngle(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const F32& val
    )
    const
  {
    ASSERT_LT(__index, this->tlmHistory_AA_ArmAngle->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of telemetry channel AA_ArmAngle\n"
      << "  Expected: Less than size of history ("
      << this->tlmHistory_AA_ArmAngle->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const TlmEntry_AA_ArmAngle& e =
      this->tlmHistory_AA_ArmAngle->at(__index);
    ASSERT_EQ(val, e.arg)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value at index "
      << __index
      << " on telmetry channel AA_ArmAngle\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.arg << "\n";
  }

  // ----------------------------------------------------------------------
  // Channel: AA_ClawTiltAngle
  // ----------------------------------------------------------------------

  void ArmAppGTestBase ::
    assertTlm_AA_ClawTiltAngle_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(this->tlmHistory_AA_ClawTiltAngle->size(), size)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for telemetry channel AA_ClawTiltAngle\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmHistory_AA_ClawTiltAngle->size() << "\n";
  }

  void ArmAppGTestBase ::
    assertTlm_AA_ClawTiltAngle(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const F32& val
    )
    const
  {
    ASSERT_LT(__index, this->tlmHistory_AA_ClawTiltAngle->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of telemetry channel AA_ClawTiltAngle\n"
      << "  Expected: Less than size of history ("
      << this->tlmHistory_AA_ClawTiltAngle->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const TlmEntry_AA_ClawTiltAngle& e =
      this->tlmHistory_AA_ClawTiltAngle->at(__index);
    ASSERT_EQ(val, e.arg)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value at index "
      << __index
      << " on telmetry channel AA_ClawTiltAngle\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.arg << "\n";
  }

  // ----------------------------------------------------------------------
  // Events
  // ----------------------------------------------------------------------

  void ArmAppGTestBase ::
    assertEvents_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventsSize)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Total size of all event histories\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventsSize << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: AA_ClawAngleCmd
  // ----------------------------------------------------------------------

  void ArmAppGTestBase ::
    assertEvents_AA_ClawAngleCmd_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_AA_ClawAngleCmd->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event AA_ClawAngleCmd\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_AA_ClawAngleCmd->size() << "\n";
  }

  void ArmAppGTestBase ::
    assertEvents_AA_ClawAngleCmd(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const F32 angle
    ) const
  {
    ASSERT_GT(this->eventHistory_AA_ClawAngleCmd->size(), __index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event AA_ClawAngleCmd\n"
      << "  Expected: Less than size of history ("
      << this->eventHistory_AA_ClawAngleCmd->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_AA_ClawAngleCmd& e =
      this->eventHistory_AA_ClawAngleCmd->at(__index);
    ASSERT_EQ(angle, e.angle)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument angle at index "
      << __index
      << " in history of event AA_ClawAngleCmd\n"
      << "  Expected: " << angle << "\n"
      << "  Actual:   " << e.angle << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: AA_BaseAngleCmd
  // ----------------------------------------------------------------------

  void ArmAppGTestBase ::
    assertEvents_AA_BaseAngleCmd_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_AA_BaseAngleCmd->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event AA_BaseAngleCmd\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_AA_BaseAngleCmd->size() << "\n";
  }

  void ArmAppGTestBase ::
    assertEvents_AA_BaseAngleCmd(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const F32 angle
    ) const
  {
    ASSERT_GT(this->eventHistory_AA_BaseAngleCmd->size(), __index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event AA_BaseAngleCmd\n"
      << "  Expected: Less than size of history ("
      << this->eventHistory_AA_BaseAngleCmd->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_AA_BaseAngleCmd& e =
      this->eventHistory_AA_BaseAngleCmd->at(__index);
    ASSERT_EQ(angle, e.angle)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument angle at index "
      << __index
      << " in history of event AA_BaseAngleCmd\n"
      << "  Expected: " << angle << "\n"
      << "  Actual:   " << e.angle << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: AA_ArmAngleCmd
  // ----------------------------------------------------------------------

  void ArmAppGTestBase ::
    assertEvents_AA_ArmAngleCmd_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_AA_ArmAngleCmd->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event AA_ArmAngleCmd\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_AA_ArmAngleCmd->size() << "\n";
  }

  void ArmAppGTestBase ::
    assertEvents_AA_ArmAngleCmd(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const F32 angle
    ) const
  {
    ASSERT_GT(this->eventHistory_AA_ArmAngleCmd->size(), __index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event AA_ArmAngleCmd\n"
      << "  Expected: Less than size of history ("
      << this->eventHistory_AA_ArmAngleCmd->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_AA_ArmAngleCmd& e =
      this->eventHistory_AA_ArmAngleCmd->at(__index);
    ASSERT_EQ(angle, e.angle)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument angle at index "
      << __index
      << " in history of event AA_ArmAngleCmd\n"
      << "  Expected: " << angle << "\n"
      << "  Actual:   " << e.angle << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: AA_ClawTiltAngleCmd
  // ----------------------------------------------------------------------

  void ArmAppGTestBase ::
    assertEvents_AA_ClawTiltAngleCmd_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_AA_ClawTiltAngleCmd->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event AA_ClawTiltAngleCmd\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_AA_ClawTiltAngleCmd->size() << "\n";
  }

  void ArmAppGTestBase ::
    assertEvents_AA_ClawTiltAngleCmd(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const F32 angle
    ) const
  {
    ASSERT_GT(this->eventHistory_AA_ClawTiltAngleCmd->size(), __index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event AA_ClawTiltAngleCmd\n"
      << "  Expected: Less than size of history ("
      << this->eventHistory_AA_ClawTiltAngleCmd->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_AA_ClawTiltAngleCmd& e =
      this->eventHistory_AA_ClawTiltAngleCmd->at(__index);
    ASSERT_EQ(angle, e.angle)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument angle at index "
      << __index
      << " in history of event AA_ClawTiltAngleCmd\n"
      << "  Expected: " << angle << "\n"
      << "  Actual:   " << e.angle << "\n";
  }

  // ----------------------------------------------------------------------
  // From ports
  // ----------------------------------------------------------------------

  void ArmAppGTestBase ::
    assertFromPortHistory_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->fromPortHistorySize)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Total size of all from port histories\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->fromPortHistorySize << "\n";
  }

  // ----------------------------------------------------------------------
  // From port: position
  // ----------------------------------------------------------------------

  void ArmAppGTestBase ::
    assert_from_position_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->fromPortHistory_position->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for from_position\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->fromPortHistory_position->size() << "\n";
  }

} // end namespace RobotArm

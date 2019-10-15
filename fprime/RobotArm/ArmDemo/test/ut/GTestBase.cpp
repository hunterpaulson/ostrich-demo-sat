// ======================================================================
// \title  ArmDemo/test/ut/GTestBase.cpp
// \author Auto-generated
// \brief  cpp file for ArmDemo component Google Test harness base class
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

  ArmDemoGTestBase ::
    ArmDemoGTestBase(
#if FW_OBJECT_NAMES == 1
        const char *const compName,
        const U32 maxHistorySize
#else
        const U32 maxHistorySize
#endif
    ) :
        ArmDemoTesterBase (
#if FW_OBJECT_NAMES == 1
            compName,
#endif
            maxHistorySize
        )
  {

  }

  ArmDemoGTestBase ::
    ~ArmDemoGTestBase(void)
  {

  }

  // ----------------------------------------------------------------------
  // Commands
  // ----------------------------------------------------------------------

  void ArmDemoGTestBase ::
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

  void ArmDemoGTestBase ::
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

  void ArmDemoGTestBase ::
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

  void ArmDemoGTestBase ::
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

  void ArmDemoGTestBase ::
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

  void ArmDemoGTestBase ::
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

  void ArmDemoGTestBase ::
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
  // Channel: AA_ArmHeightAngle
  // ----------------------------------------------------------------------

  void ArmDemoGTestBase ::
    assertTlm_AA_ArmHeightAngle_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(this->tlmHistory_AA_ArmHeightAngle->size(), size)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for telemetry channel AA_ArmHeightAngle\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmHistory_AA_ArmHeightAngle->size() << "\n";
  }

  void ArmDemoGTestBase ::
    assertTlm_AA_ArmHeightAngle(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const F32& val
    )
    const
  {
    ASSERT_LT(__index, this->tlmHistory_AA_ArmHeightAngle->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of telemetry channel AA_ArmHeightAngle\n"
      << "  Expected: Less than size of history ("
      << this->tlmHistory_AA_ArmHeightAngle->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const TlmEntry_AA_ArmHeightAngle& e =
      this->tlmHistory_AA_ArmHeightAngle->at(__index);
    ASSERT_EQ(val, e.arg)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value at index "
      << __index
      << " on telmetry channel AA_ArmHeightAngle\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.arg << "\n";
  }

  // ----------------------------------------------------------------------
  // Channel: AA_ArmLengthAngle
  // ----------------------------------------------------------------------

  void ArmDemoGTestBase ::
    assertTlm_AA_ArmLengthAngle_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(this->tlmHistory_AA_ArmLengthAngle->size(), size)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for telemetry channel AA_ArmLengthAngle\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmHistory_AA_ArmLengthAngle->size() << "\n";
  }

  void ArmDemoGTestBase ::
    assertTlm_AA_ArmLengthAngle(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const F32& val
    )
    const
  {
    ASSERT_LT(__index, this->tlmHistory_AA_ArmLengthAngle->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of telemetry channel AA_ArmLengthAngle\n"
      << "  Expected: Less than size of history ("
      << this->tlmHistory_AA_ArmLengthAngle->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const TlmEntry_AA_ArmLengthAngle& e =
      this->tlmHistory_AA_ArmLengthAngle->at(__index);
    ASSERT_EQ(val, e.arg)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value at index "
      << __index
      << " on telmetry channel AA_ArmLengthAngle\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.arg << "\n";
  }

  // ----------------------------------------------------------------------
  // Channel: AA_Cycles
  // ----------------------------------------------------------------------

  void ArmDemoGTestBase ::
    assertTlm_AA_Cycles_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(this->tlmHistory_AA_Cycles->size(), size)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for telemetry channel AA_Cycles\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmHistory_AA_Cycles->size() << "\n";
  }

  void ArmDemoGTestBase ::
    assertTlm_AA_Cycles(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const U32& val
    )
    const
  {
    ASSERT_LT(__index, this->tlmHistory_AA_Cycles->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of telemetry channel AA_Cycles\n"
      << "  Expected: Less than size of history ("
      << this->tlmHistory_AA_Cycles->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const TlmEntry_AA_Cycles& e =
      this->tlmHistory_AA_Cycles->at(__index);
    ASSERT_EQ(val, e.arg)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value at index "
      << __index
      << " on telmetry channel AA_Cycles\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.arg << "\n";
  }

  // ----------------------------------------------------------------------
  // Events
  // ----------------------------------------------------------------------

  void ArmDemoGTestBase ::
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

  void ArmDemoGTestBase ::
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

  void ArmDemoGTestBase ::
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

  void ArmDemoGTestBase ::
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

  void ArmDemoGTestBase ::
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
  // Event: AA_ArmLengthAngleCmd
  // ----------------------------------------------------------------------

  void ArmDemoGTestBase ::
    assertEvents_AA_ArmLengthAngleCmd_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_AA_ArmLengthAngleCmd->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event AA_ArmLengthAngleCmd\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_AA_ArmLengthAngleCmd->size() << "\n";
  }

  void ArmDemoGTestBase ::
    assertEvents_AA_ArmLengthAngleCmd(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const F32 angle
    ) const
  {
    ASSERT_GT(this->eventHistory_AA_ArmLengthAngleCmd->size(), __index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event AA_ArmLengthAngleCmd\n"
      << "  Expected: Less than size of history ("
      << this->eventHistory_AA_ArmLengthAngleCmd->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_AA_ArmLengthAngleCmd& e =
      this->eventHistory_AA_ArmLengthAngleCmd->at(__index);
    ASSERT_EQ(angle, e.angle)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument angle at index "
      << __index
      << " in history of event AA_ArmLengthAngleCmd\n"
      << "  Expected: " << angle << "\n"
      << "  Actual:   " << e.angle << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: AA_ArmHeightAngleCmd
  // ----------------------------------------------------------------------

  void ArmDemoGTestBase ::
    assertEvents_AA_ArmHeightAngleCmd_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_AA_ArmHeightAngleCmd->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event AA_ArmHeightAngleCmd\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_AA_ArmHeightAngleCmd->size() << "\n";
  }

  void ArmDemoGTestBase ::
    assertEvents_AA_ArmHeightAngleCmd(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 __index,
        const F32 angle
    ) const
  {
    ASSERT_GT(this->eventHistory_AA_ArmHeightAngleCmd->size(), __index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event AA_ArmHeightAngleCmd\n"
      << "  Expected: Less than size of history ("
      << this->eventHistory_AA_ArmHeightAngleCmd->size() << ")\n"
      << "  Actual:   " << __index << "\n";
    const EventEntry_AA_ArmHeightAngleCmd& e =
      this->eventHistory_AA_ArmHeightAngleCmd->at(__index);
    ASSERT_EQ(angle, e.angle)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument angle at index "
      << __index
      << " in history of event AA_ArmHeightAngleCmd\n"
      << "  Expected: " << angle << "\n"
      << "  Actual:   " << e.angle << "\n";
  }

  // ----------------------------------------------------------------------
  // From ports
  // ----------------------------------------------------------------------

  void ArmDemoGTestBase ::
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

  void ArmDemoGTestBase ::
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

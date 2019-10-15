// ======================================================================
// \title  ArmDemo/test/ut/TesterBase.cpp
// \author Auto-generated
// \brief  cpp file for ArmDemo component test harness base class
//
// \copyright
// Copyright 2009-2016, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#include <stdlib.h>
#include <string.h>
#include "TesterBase.hpp"

namespace RobotArm {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  ArmDemoTesterBase ::
    ArmDemoTesterBase(
#if FW_OBJECT_NAMES == 1
        const char *const compName,
        const U32 maxHistorySize
#else
        const U32 maxHistorySize
#endif
    ) :
#if FW_OBJECT_NAMES == 1
      Fw::PassiveComponentBase(compName)
#else
      Fw::PassiveComponentBase()
#endif
  {
    // Initialize command history
    this->cmdResponseHistory = new History<CmdResponse>(maxHistorySize);
    // Initialize telemetry histories
    this->tlmHistory_AA_ClawAngle =
      new History<TlmEntry_AA_ClawAngle>(maxHistorySize);
    this->tlmHistory_AA_BaseAngle =
      new History<TlmEntry_AA_BaseAngle>(maxHistorySize);
    this->tlmHistory_AA_ArmHeightAngle =
      new History<TlmEntry_AA_ArmHeightAngle>(maxHistorySize);
    this->tlmHistory_AA_ArmLengthAngle =
      new History<TlmEntry_AA_ArmLengthAngle>(maxHistorySize);
    this->tlmHistory_AA_Cycles =
      new History<TlmEntry_AA_Cycles>(maxHistorySize);
    // Initialize event histories
#if FW_ENABLE_TEXT_LOGGING
    this->textLogHistory = new History<TextLogEntry>(maxHistorySize);
#endif
    this->eventHistory_AA_ClawAngleCmd =
      new History<EventEntry_AA_ClawAngleCmd>(maxHistorySize);
    this->eventHistory_AA_BaseAngleCmd =
      new History<EventEntry_AA_BaseAngleCmd>(maxHistorySize);
    this->eventHistory_AA_ArmLengthAngleCmd =
      new History<EventEntry_AA_ArmLengthAngleCmd>(maxHistorySize);
    this->eventHistory_AA_ArmHeightAngleCmd =
      new History<EventEntry_AA_ArmHeightAngleCmd>(maxHistorySize);
    // Initialize histories for typed user output ports
    this->fromPortHistory_position =
      new History<FromPortEntry_position>(maxHistorySize);
    // Clear history
    this->clearHistory();
  }

  ArmDemoTesterBase ::
    ~ArmDemoTesterBase(void)
  {
    // Destroy command history
    delete this->cmdResponseHistory;
    // Destroy telemetry histories
    delete this->tlmHistory_AA_ClawAngle;
    delete this->tlmHistory_AA_BaseAngle;
    delete this->tlmHistory_AA_ArmHeightAngle;
    delete this->tlmHistory_AA_ArmLengthAngle;
    delete this->tlmHistory_AA_Cycles;
    // Destroy event histories
#if FW_ENABLE_TEXT_LOGGING
    delete this->textLogHistory;
#endif
    delete this->eventHistory_AA_ClawAngleCmd;
    delete this->eventHistory_AA_BaseAngleCmd;
    delete this->eventHistory_AA_ArmLengthAngleCmd;
    delete this->eventHistory_AA_ArmHeightAngleCmd;
  }

  void ArmDemoTesterBase ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {

    // Initialize base class

		Fw::PassiveComponentBase::init(instance);

    // Attach input port position

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_position();
        ++_port
    ) {

      this->m_from_position[_port].init();
      this->m_from_position[_port].addCallComp(
          this,
          from_position_static
      );
      this->m_from_position[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_position[%d]",
          this->m_objName,
          _port
      );
      this->m_from_position[_port].setObjName(_portName);
#endif

    }

    // Attach input port CmdStatus

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_CmdStatus();
        ++_port
    ) {

      this->m_from_CmdStatus[_port].init();
      this->m_from_CmdStatus[_port].addCallComp(
          this,
          from_CmdStatus_static
      );
      this->m_from_CmdStatus[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_CmdStatus[%d]",
          this->m_objName,
          _port
      );
      this->m_from_CmdStatus[_port].setObjName(_portName);
#endif

    }

    // Attach input port CmdReg

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_CmdReg();
        ++_port
    ) {

      this->m_from_CmdReg[_port].init();
      this->m_from_CmdReg[_port].addCallComp(
          this,
          from_CmdReg_static
      );
      this->m_from_CmdReg[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_CmdReg[%d]",
          this->m_objName,
          _port
      );
      this->m_from_CmdReg[_port].setObjName(_portName);
#endif

    }

    // Attach input port Tlm

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_Tlm();
        ++_port
    ) {

      this->m_from_Tlm[_port].init();
      this->m_from_Tlm[_port].addCallComp(
          this,
          from_Tlm_static
      );
      this->m_from_Tlm[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_Tlm[%d]",
          this->m_objName,
          _port
      );
      this->m_from_Tlm[_port].setObjName(_portName);
#endif

    }

    // Attach input port Time

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_Time();
        ++_port
    ) {

      this->m_from_Time[_port].init();
      this->m_from_Time[_port].addCallComp(
          this,
          from_Time_static
      );
      this->m_from_Time[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_Time[%d]",
          this->m_objName,
          _port
      );
      this->m_from_Time[_port].setObjName(_portName);
#endif

    }

    // Attach input port Log

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_Log();
        ++_port
    ) {

      this->m_from_Log[_port].init();
      this->m_from_Log[_port].addCallComp(
          this,
          from_Log_static
      );
      this->m_from_Log[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_Log[%d]",
          this->m_objName,
          _port
      );
      this->m_from_Log[_port].setObjName(_portName);
#endif

    }

    // Attach input port LogText

#if FW_ENABLE_TEXT_LOGGING == 1
    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_LogText();
        ++_port
    ) {

      this->m_from_LogText[_port].init();
      this->m_from_LogText[_port].addCallComp(
          this,
          from_LogText_static
      );
      this->m_from_LogText[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_LogText[%d]",
          this->m_objName,
          _port
      );
      this->m_from_LogText[_port].setObjName(_portName);
#endif

    }
#endif

    // Initialize output port Run

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_to_Run();
        ++_port
    ) {
      this->m_to_Run[_port].init();

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      snprintf(
          _portName,
          sizeof(_portName),
          "%s_to_Run[%d]",
          this->m_objName,
          _port
      );
      this->m_to_Run[_port].setObjName(_portName);
#endif

    }

  }

  // ----------------------------------------------------------------------
  // Getters for port counts
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE ArmDemoTesterBase ::
    getNum_from_position(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_position);
  }

  NATIVE_INT_TYPE ArmDemoTesterBase ::
    getNum_to_Run(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_to_Run);
  }

  NATIVE_INT_TYPE ArmDemoTesterBase ::
    getNum_to_CmdDisp(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_to_CmdDisp);
  }

  NATIVE_INT_TYPE ArmDemoTesterBase ::
    getNum_from_CmdStatus(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_CmdStatus);
  }

  NATIVE_INT_TYPE ArmDemoTesterBase ::
    getNum_from_CmdReg(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_CmdReg);
  }

  NATIVE_INT_TYPE ArmDemoTesterBase ::
    getNum_from_Tlm(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_Tlm);
  }

  NATIVE_INT_TYPE ArmDemoTesterBase ::
    getNum_from_Time(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_Time);
  }

  NATIVE_INT_TYPE ArmDemoTesterBase ::
    getNum_from_Log(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_Log);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  NATIVE_INT_TYPE ArmDemoTesterBase ::
    getNum_from_LogText(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_LogText);
  }
#endif

  // ----------------------------------------------------------------------
  // Connectors for to ports
  // ----------------------------------------------------------------------

  void ArmDemoTesterBase ::
    connect_to_Run(
        const NATIVE_INT_TYPE portNum,
        Svc::InputSchedPort *const Run
    )
  {
    FW_ASSERT(portNum < this->getNum_to_Run(),static_cast<AssertArg>(portNum));
    this->m_to_Run[portNum].addCallPort(Run);
  }

  void ArmDemoTesterBase ::
    connect_to_CmdDisp(
        const NATIVE_INT_TYPE portNum,
        Fw::InputCmdPort *const CmdDisp
    )
  {
    FW_ASSERT(portNum < this->getNum_to_CmdDisp(),static_cast<AssertArg>(portNum));
    this->m_to_CmdDisp[portNum].addCallPort(CmdDisp);
  }


  // ----------------------------------------------------------------------
  // Invocation functions for to ports
  // ----------------------------------------------------------------------

  void ArmDemoTesterBase ::
    invoke_to_Run(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    FW_ASSERT(portNum < this->getNum_to_Run(),static_cast<AssertArg>(portNum));
    FW_ASSERT(portNum < this->getNum_to_Run(),static_cast<AssertArg>(portNum));
    this->m_to_Run[portNum].invoke(
        context
    );
  }

  // ----------------------------------------------------------------------
  // Connection status for to ports
  // ----------------------------------------------------------------------

  bool ArmDemoTesterBase ::
    isConnected_to_Run(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_to_Run(), static_cast<AssertArg>(portNum));
    return this->m_to_Run[portNum].isConnected();
  }

  bool ArmDemoTesterBase ::
    isConnected_to_CmdDisp(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_to_CmdDisp(), static_cast<AssertArg>(portNum));
    return this->m_to_CmdDisp[portNum].isConnected();
  }

  // ----------------------------------------------------------------------
  // Getters for from ports
  // ----------------------------------------------------------------------

  RobotArm::InputServoSetPort *ArmDemoTesterBase ::
    get_from_position(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_position(),static_cast<AssertArg>(portNum));
    return &this->m_from_position[portNum];
  }

  Fw::InputCmdResponsePort *ArmDemoTesterBase ::
    get_from_CmdStatus(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_CmdStatus(),static_cast<AssertArg>(portNum));
    return &this->m_from_CmdStatus[portNum];
  }

  Fw::InputCmdRegPort *ArmDemoTesterBase ::
    get_from_CmdReg(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_CmdReg(),static_cast<AssertArg>(portNum));
    return &this->m_from_CmdReg[portNum];
  }

  Fw::InputTlmPort *ArmDemoTesterBase ::
    get_from_Tlm(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_Tlm(),static_cast<AssertArg>(portNum));
    return &this->m_from_Tlm[portNum];
  }

  Fw::InputTimePort *ArmDemoTesterBase ::
    get_from_Time(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_Time(),static_cast<AssertArg>(portNum));
    return &this->m_from_Time[portNum];
  }

  Fw::InputLogPort *ArmDemoTesterBase ::
    get_from_Log(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_Log(),static_cast<AssertArg>(portNum));
    return &this->m_from_Log[portNum];
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  Fw::InputLogTextPort *ArmDemoTesterBase ::
    get_from_LogText(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_LogText(),static_cast<AssertArg>(portNum));
    return &this->m_from_LogText[portNum];
  }
#endif

  // ----------------------------------------------------------------------
  // Static functions for from ports
  // ----------------------------------------------------------------------

  void ArmDemoTesterBase ::
    from_position_static(
        Fw::PassiveComponentBase *const callComp,
        const NATIVE_INT_TYPE portNum,
        F32 angle
    )
  {
    FW_ASSERT(callComp);
    ArmDemoTesterBase* _testerBase =
      static_cast<ArmDemoTesterBase*>(callComp);
    _testerBase->from_position_handlerBase(
        portNum,
        angle
    );
  }

  void ArmDemoTesterBase ::
    from_CmdStatus_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        const Fw::CommandResponse response
    )
  {
    ArmDemoTesterBase* _testerBase =
      static_cast<ArmDemoTesterBase*>(component);
    _testerBase->cmdResponseIn(opCode, cmdSeq, response);
  }

  void ArmDemoTesterBase ::
    from_CmdReg_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        const FwOpcodeType opCode
    )
  {

  }

  void ArmDemoTesterBase ::
    from_Tlm_static(
        Fw::PassiveComponentBase *const component,
        NATIVE_INT_TYPE portNum,
        FwChanIdType id,
        Fw::Time &timeTag,
        Fw::TlmBuffer &val
    )
  {
    ArmDemoTesterBase* _testerBase =
      static_cast<ArmDemoTesterBase*>(component);
    _testerBase->dispatchTlm(id, timeTag, val);
  }

  void ArmDemoTesterBase ::
    from_Log_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        FwEventIdType id,
        Fw::Time &timeTag,
        Fw::LogSeverity severity,
        Fw::LogBuffer &args
    )
  {
    ArmDemoTesterBase* _testerBase =
      static_cast<ArmDemoTesterBase*>(component);
    _testerBase->dispatchEvents(id, timeTag, severity, args);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  void ArmDemoTesterBase ::
    from_LogText_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        FwEventIdType id,
        Fw::Time &timeTag,
        Fw::TextLogSeverity severity,
        Fw::TextLogString &text
    )
  {
    ArmDemoTesterBase* _testerBase =
      static_cast<ArmDemoTesterBase*>(component);
    _testerBase->textLogIn(id,timeTag,severity,text);
  }
#endif

  void ArmDemoTesterBase ::
    from_Time_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        Fw::Time& time
    )
  {
    ArmDemoTesterBase* _testerBase =
      static_cast<ArmDemoTesterBase*>(component);
    time = _testerBase->m_testTime;
  }

  // ----------------------------------------------------------------------
  // Histories for typed from ports
  // ----------------------------------------------------------------------

  void ArmDemoTesterBase ::
    clearFromPortHistory(void)
  {
    this->fromPortHistorySize = 0;
    this->fromPortHistory_position->clear();
  }

  // ----------------------------------------------------------------------
  // From port: position
  // ----------------------------------------------------------------------

  void ArmDemoTesterBase ::
    pushFromPortEntry_position(
        F32 angle
    )
  {
    FromPortEntry_position _e = {
      angle
    };
    this->fromPortHistory_position->push_back(_e);
    ++this->fromPortHistorySize;
  }

  // ----------------------------------------------------------------------
  // Handler base functions for from ports
  // ----------------------------------------------------------------------

  void ArmDemoTesterBase ::
    from_position_handlerBase(
        const NATIVE_INT_TYPE portNum,
        F32 angle
    )
  {
    FW_ASSERT(portNum < this->getNum_from_position(),static_cast<AssertArg>(portNum));
    this->from_position_handler(
        portNum,
        angle
    );
  }

  // ----------------------------------------------------------------------
  // Command response handling
  // ----------------------------------------------------------------------

  void ArmDemoTesterBase ::
    cmdResponseIn(
        const FwOpcodeType opCode,
        const U32 seq,
        const Fw::CommandResponse response
    )
  {
    CmdResponse e = { opCode, seq, response };
    this->cmdResponseHistory->push_back(e);
  }

  // ----------------------------------------------------------------------
  // Command: AA_CLAW_ANG
  // ----------------------------------------------------------------------

  void ArmDemoTesterBase ::
    sendCmd_AA_CLAW_ANG(
        const NATIVE_INT_TYPE instance,
        const U32 cmdSeq,
        F32 angle
    )
  {

    // Serialize arguments

    Fw::CmdArgBuffer buff;
    Fw::SerializeStatus _status;
    _status = buff.serialize(angle);
    FW_ASSERT(_status == Fw::FW_SERIALIZE_OK,static_cast<AssertArg>(_status));

    // Call output command port

    FwOpcodeType _opcode;
    const U32 idBase = this->getIdBase();
    _opcode = ArmDemoComponentBase::OPCODE_AA_CLAW_ANG + idBase;

    if (this->m_to_CmdDisp[0].isConnected()) {
      this->m_to_CmdDisp[0].invoke(
          _opcode,
          cmdSeq,
          buff
      );
    }
    else {
      printf("Test Command Output port not connected!\n");
    }

  }

  // ----------------------------------------------------------------------
  // Command: AA_BASE_ANG
  // ----------------------------------------------------------------------

  void ArmDemoTesterBase ::
    sendCmd_AA_BASE_ANG(
        const NATIVE_INT_TYPE instance,
        const U32 cmdSeq,
        F32 angle
    )
  {

    // Serialize arguments

    Fw::CmdArgBuffer buff;
    Fw::SerializeStatus _status;
    _status = buff.serialize(angle);
    FW_ASSERT(_status == Fw::FW_SERIALIZE_OK,static_cast<AssertArg>(_status));

    // Call output command port

    FwOpcodeType _opcode;
    const U32 idBase = this->getIdBase();
    _opcode = ArmDemoComponentBase::OPCODE_AA_BASE_ANG + idBase;

    if (this->m_to_CmdDisp[0].isConnected()) {
      this->m_to_CmdDisp[0].invoke(
          _opcode,
          cmdSeq,
          buff
      );
    }
    else {
      printf("Test Command Output port not connected!\n");
    }

  }

  // ----------------------------------------------------------------------
  // Command: AA_ARM_HEIGHT_ANG
  // ----------------------------------------------------------------------

  void ArmDemoTesterBase ::
    sendCmd_AA_ARM_HEIGHT_ANG(
        const NATIVE_INT_TYPE instance,
        const U32 cmdSeq,
        F32 angle
    )
  {

    // Serialize arguments

    Fw::CmdArgBuffer buff;
    Fw::SerializeStatus _status;
    _status = buff.serialize(angle);
    FW_ASSERT(_status == Fw::FW_SERIALIZE_OK,static_cast<AssertArg>(_status));

    // Call output command port

    FwOpcodeType _opcode;
    const U32 idBase = this->getIdBase();
    _opcode = ArmDemoComponentBase::OPCODE_AA_ARM_HEIGHT_ANG + idBase;

    if (this->m_to_CmdDisp[0].isConnected()) {
      this->m_to_CmdDisp[0].invoke(
          _opcode,
          cmdSeq,
          buff
      );
    }
    else {
      printf("Test Command Output port not connected!\n");
    }

  }

  // ----------------------------------------------------------------------
  // Command: AA_ARM_LENGTH_ANG
  // ----------------------------------------------------------------------

  void ArmDemoTesterBase ::
    sendCmd_AA_ARM_LENGTH_ANG(
        const NATIVE_INT_TYPE instance,
        const U32 cmdSeq,
        F32 angle
    )
  {

    // Serialize arguments

    Fw::CmdArgBuffer buff;
    Fw::SerializeStatus _status;
    _status = buff.serialize(angle);
    FW_ASSERT(_status == Fw::FW_SERIALIZE_OK,static_cast<AssertArg>(_status));

    // Call output command port

    FwOpcodeType _opcode;
    const U32 idBase = this->getIdBase();
    _opcode = ArmDemoComponentBase::OPCODE_AA_ARM_LENGTH_ANG + idBase;

    if (this->m_to_CmdDisp[0].isConnected()) {
      this->m_to_CmdDisp[0].invoke(
          _opcode,
          cmdSeq,
          buff
      );
    }
    else {
      printf("Test Command Output port not connected!\n");
    }

  }


  void ArmDemoTesterBase ::
    sendRawCmd(FwOpcodeType opcode, U32 cmdSeq, Fw::CmdArgBuffer& args) {

    const U32 idBase = this->getIdBase();
    FwOpcodeType _opcode = opcode + idBase;
    if (this->m_to_CmdDisp[0].isConnected()) {
      this->m_to_CmdDisp[0].invoke(
          _opcode,
          cmdSeq,
          args
      );
    }
    else {
      printf("Test Command Output port not connected!\n");
    }

  }

  // ----------------------------------------------------------------------
  // History
  // ----------------------------------------------------------------------

  void ArmDemoTesterBase ::
    clearHistory()
  {
    this->cmdResponseHistory->clear();
    this->clearTlm();
    this->textLogHistory->clear();
    this->clearEvents();
    this->clearFromPortHistory();
  }

  // ----------------------------------------------------------------------
  // Time
  // ----------------------------------------------------------------------

  void ArmDemoTesterBase ::
    setTestTime(const Fw::Time& time)
  {
    this->m_testTime = time;
  }

  // ----------------------------------------------------------------------
  // Telemetry dispatch
  // ----------------------------------------------------------------------

  void ArmDemoTesterBase ::
    dispatchTlm(
        const FwChanIdType id,
        const Fw::Time &timeTag,
        Fw::TlmBuffer &val
    )
  {

    val.resetDeser();

    const U32 idBase = this->getIdBase();
    FW_ASSERT(id >= idBase, id, idBase);

    switch (id - idBase) {

      case ArmDemoComponentBase::CHANNELID_AA_CLAWANGLE:
      {
        F32 arg;
        const Fw::SerializeStatus _status = val.deserialize(arg);
        if (_status != Fw::FW_SERIALIZE_OK) {
          printf("Error deserializing AA_ClawAngle: %d\n", _status);
          return;
        }
        this->tlmInput_AA_ClawAngle(timeTag, arg);
        break;
      }

      case ArmDemoComponentBase::CHANNELID_AA_BASEANGLE:
      {
        F32 arg;
        const Fw::SerializeStatus _status = val.deserialize(arg);
        if (_status != Fw::FW_SERIALIZE_OK) {
          printf("Error deserializing AA_BaseAngle: %d\n", _status);
          return;
        }
        this->tlmInput_AA_BaseAngle(timeTag, arg);
        break;
      }

      case ArmDemoComponentBase::CHANNELID_AA_ARMHEIGHTANGLE:
      {
        F32 arg;
        const Fw::SerializeStatus _status = val.deserialize(arg);
        if (_status != Fw::FW_SERIALIZE_OK) {
          printf("Error deserializing AA_ArmHeightAngle: %d\n", _status);
          return;
        }
        this->tlmInput_AA_ArmHeightAngle(timeTag, arg);
        break;
      }

      case ArmDemoComponentBase::CHANNELID_AA_ARMLENGTHANGLE:
      {
        F32 arg;
        const Fw::SerializeStatus _status = val.deserialize(arg);
        if (_status != Fw::FW_SERIALIZE_OK) {
          printf("Error deserializing AA_ArmLengthAngle: %d\n", _status);
          return;
        }
        this->tlmInput_AA_ArmLengthAngle(timeTag, arg);
        break;
      }

      case ArmDemoComponentBase::CHANNELID_AA_CYCLES:
      {
        U32 arg;
        const Fw::SerializeStatus _status = val.deserialize(arg);
        if (_status != Fw::FW_SERIALIZE_OK) {
          printf("Error deserializing AA_Cycles: %d\n", _status);
          return;
        }
        this->tlmInput_AA_Cycles(timeTag, arg);
        break;
      }

      default: {
        FW_ASSERT(0, id);
        break;
      }

    }

  }

  void ArmDemoTesterBase ::
    clearTlm(void)
  {
    this->tlmSize = 0;
    this->tlmHistory_AA_ClawAngle->clear();
    this->tlmHistory_AA_BaseAngle->clear();
    this->tlmHistory_AA_ArmHeightAngle->clear();
    this->tlmHistory_AA_ArmLengthAngle->clear();
    this->tlmHistory_AA_Cycles->clear();
  }

  // ----------------------------------------------------------------------
  // Channel: AA_ClawAngle
  // ----------------------------------------------------------------------

  void ArmDemoTesterBase ::
    tlmInput_AA_ClawAngle(
        const Fw::Time& timeTag,
        const F32& val
    )
  {
    TlmEntry_AA_ClawAngle e = { timeTag, val };
    this->tlmHistory_AA_ClawAngle->push_back(e);
    ++this->tlmSize;
  }

  // ----------------------------------------------------------------------
  // Channel: AA_BaseAngle
  // ----------------------------------------------------------------------

  void ArmDemoTesterBase ::
    tlmInput_AA_BaseAngle(
        const Fw::Time& timeTag,
        const F32& val
    )
  {
    TlmEntry_AA_BaseAngle e = { timeTag, val };
    this->tlmHistory_AA_BaseAngle->push_back(e);
    ++this->tlmSize;
  }

  // ----------------------------------------------------------------------
  // Channel: AA_ArmHeightAngle
  // ----------------------------------------------------------------------

  void ArmDemoTesterBase ::
    tlmInput_AA_ArmHeightAngle(
        const Fw::Time& timeTag,
        const F32& val
    )
  {
    TlmEntry_AA_ArmHeightAngle e = { timeTag, val };
    this->tlmHistory_AA_ArmHeightAngle->push_back(e);
    ++this->tlmSize;
  }

  // ----------------------------------------------------------------------
  // Channel: AA_ArmLengthAngle
  // ----------------------------------------------------------------------

  void ArmDemoTesterBase ::
    tlmInput_AA_ArmLengthAngle(
        const Fw::Time& timeTag,
        const F32& val
    )
  {
    TlmEntry_AA_ArmLengthAngle e = { timeTag, val };
    this->tlmHistory_AA_ArmLengthAngle->push_back(e);
    ++this->tlmSize;
  }

  // ----------------------------------------------------------------------
  // Channel: AA_Cycles
  // ----------------------------------------------------------------------

  void ArmDemoTesterBase ::
    tlmInput_AA_Cycles(
        const Fw::Time& timeTag,
        const U32& val
    )
  {
    TlmEntry_AA_Cycles e = { timeTag, val };
    this->tlmHistory_AA_Cycles->push_back(e);
    ++this->tlmSize;
  }

  // ----------------------------------------------------------------------
  // Event dispatch
  // ----------------------------------------------------------------------

  void ArmDemoTesterBase ::
    dispatchEvents(
        const FwEventIdType id,
        Fw::Time &timeTag,
        const Fw::LogSeverity severity,
        Fw::LogBuffer &args
    )
  {

    args.resetDeser();

    const U32 idBase = this->getIdBase();
    FW_ASSERT(id >= idBase, id, idBase);
    switch (id - idBase) {

      case ArmDemoComponentBase::EVENTID_AA_CLAWANGLECMD:
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 1,_numArgs,1);

#endif
        F32 angle;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(F32),_argSize,sizeof(F32));
        }
#endif
        _status = args.deserialize(angle);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_ACTIVITY_HI_AA_ClawAngleCmd(angle);

        break;

      }

      case ArmDemoComponentBase::EVENTID_AA_BASEANGLECMD:
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 1,_numArgs,1);

#endif
        F32 angle;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(F32),_argSize,sizeof(F32));
        }
#endif
        _status = args.deserialize(angle);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_ACTIVITY_HI_AA_BaseAngleCmd(angle);

        break;

      }

      case ArmDemoComponentBase::EVENTID_AA_ARMLENGTHANGLECMD:
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 1,_numArgs,1);

#endif
        F32 angle;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(F32),_argSize,sizeof(F32));
        }
#endif
        _status = args.deserialize(angle);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_ACTIVITY_HI_AA_ArmLengthAngleCmd(angle);

        break;

      }

      case ArmDemoComponentBase::EVENTID_AA_ARMHEIGHTANGLECMD:
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 1,_numArgs,1);

#endif
        F32 angle;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(F32),_argSize,sizeof(F32));
        }
#endif
        _status = args.deserialize(angle);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_ACTIVITY_HI_AA_ArmHeightAngleCmd(angle);

        break;

      }

      default: {
        FW_ASSERT(0, id);
        break;
      }

    }

  }

  void ArmDemoTesterBase ::
    clearEvents(void)
  {
    this->eventsSize = 0;
    this->eventHistory_AA_ClawAngleCmd->clear();
    this->eventHistory_AA_BaseAngleCmd->clear();
    this->eventHistory_AA_ArmLengthAngleCmd->clear();
    this->eventHistory_AA_ArmHeightAngleCmd->clear();
  }

#if FW_ENABLE_TEXT_LOGGING

  // ----------------------------------------------------------------------
  // Text events
  // ----------------------------------------------------------------------

  void ArmDemoTesterBase ::
    textLogIn(
        const U32 id,
        Fw::Time &timeTag,
        const Fw::TextLogSeverity severity,
        const Fw::TextLogString &text
    )
  {
    TextLogEntry e = { id, timeTag, severity, text };
    textLogHistory->push_back(e);
  }

  void ArmDemoTesterBase ::
    printTextLogHistoryEntry(
        const TextLogEntry& e,
        FILE* file
    )
  {
    const char *severityString = "UNKNOWN";
    switch (e.severity) {
      case Fw::LOG_FATAL:
        severityString = "FATAL";
        break;
      case Fw::LOG_WARNING_HI:
        severityString = "WARNING_HI";
        break;
      case Fw::LOG_WARNING_LO:
        severityString = "WARNING_LO";
        break;
      case Fw::LOG_COMMAND:
        severityString = "COMMAND";
        break;
      case Fw::LOG_ACTIVITY_HI:
        severityString = "ACTIVITY_HI";
        break;
      case Fw::LOG_ACTIVITY_LO:
        severityString = "ACTIVITY_LO";
        break;
      case Fw::LOG_DIAGNOSTIC:
       severityString = "DIAGNOSTIC";
        break;
      default:
        severityString = "SEVERITY ERROR";
        break;
    }

    fprintf(
        file,
        "EVENT: (%d) (%d:%d,%d) %s: %s\n",
        e.id,
        const_cast<TextLogEntry&>(e).timeTag.getTimeBase(),
        const_cast<TextLogEntry&>(e).timeTag.getSeconds(),
        const_cast<TextLogEntry&>(e).timeTag.getUSeconds(),
        severityString,
        e.text.toChar()
    );

  }

  void ArmDemoTesterBase ::
    printTextLogHistory(FILE *file)
  {
    for (U32 i = 0; i < this->textLogHistory->size(); ++i) {
      this->printTextLogHistoryEntry(
          this->textLogHistory->at(i),
          file
      );
    }
  }

#endif

  // ----------------------------------------------------------------------
  // Event: AA_ClawAngleCmd
  // ----------------------------------------------------------------------

  void ArmDemoTesterBase ::
    logIn_ACTIVITY_HI_AA_ClawAngleCmd(
        F32 angle
    )
  {
    EventEntry_AA_ClawAngleCmd e = {
      angle
    };
    eventHistory_AA_ClawAngleCmd->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: AA_BaseAngleCmd
  // ----------------------------------------------------------------------

  void ArmDemoTesterBase ::
    logIn_ACTIVITY_HI_AA_BaseAngleCmd(
        F32 angle
    )
  {
    EventEntry_AA_BaseAngleCmd e = {
      angle
    };
    eventHistory_AA_BaseAngleCmd->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: AA_ArmLengthAngleCmd
  // ----------------------------------------------------------------------

  void ArmDemoTesterBase ::
    logIn_ACTIVITY_HI_AA_ArmLengthAngleCmd(
        F32 angle
    )
  {
    EventEntry_AA_ArmLengthAngleCmd e = {
      angle
    };
    eventHistory_AA_ArmLengthAngleCmd->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: AA_ArmHeightAngleCmd
  // ----------------------------------------------------------------------

  void ArmDemoTesterBase ::
    logIn_ACTIVITY_HI_AA_ArmHeightAngleCmd(
        F32 angle
    )
  {
    EventEntry_AA_ArmHeightAngleCmd e = {
      angle
    };
    eventHistory_AA_ArmHeightAngleCmd->push_back(e);
    ++this->eventsSize;
  }

} // end namespace RobotArm

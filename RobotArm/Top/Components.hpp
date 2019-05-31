#ifndef __ROBOTARM_COMPONENTS_HEADER__
#define __ROBOTARM_COMPONENTS_HEADER__

void constructRobotArmArchitecture(void);
void exitTasks(void);
void constructApp(int port_number, char* hostname);

#include <Svc/ActiveRateGroup/ActiveRateGroupImpl.hpp>
#include <Svc/RateGroupDriver/RateGroupDriverImpl.hpp>

#include <Svc/CmdDispatcher/CommandDispatcherImpl.hpp>
#include <Svc/CmdSequencer/CmdSequencerImpl.hpp>
#include <Svc/PassiveConsoleTextLogger/ConsoleTextLoggerImpl.hpp>
#include <Svc/ActiveLogger/ActiveLoggerImpl.hpp>
#include <Svc/LinuxTime/LinuxTimeImpl.hpp>
#include <Svc/LinuxTimer/LinuxTimerComponentImpl.hpp>
#include <Svc/TlmChan/TlmChanImpl.hpp>
#include <Svc/PrmDb/PrmDbImpl.hpp>
#include <Fw/Obj/SimpleObjRegistry.hpp>
#include <Svc/FileUplink/FileUplink.hpp>
#include <Svc/FileDownlink/FileDownlink.hpp>
#include <Svc/BufferManager/BufferManager.hpp>
#include <Svc/Health/HealthComponentImpl.hpp>

#include <Svc/SocketGndIf/SvcSocketGndIfImpl.hpp>

#include <Svc/AssertFatalAdapter/AssertFatalAdapterComponentImpl.hpp>
#include <Svc/FatalHandler/FatalHandlerComponentImpl.hpp>

// Drivers

#include <Drv/LinuxI2cDriver/LinuxI2cDriverComponentImpl.hpp>

// servo controller
#include <RobotArm/PcaServo/PcaServoComponentImpl.hpp>

// Main app
#include <RobotArm/ArmApp/ArmAppComponentImpl.hpp>

extern Svc::RateGroupDriverImpl rateGroupDriverComp;
extern Svc::ActiveRateGroupImpl rateGroup1HzComp;
extern Svc::CmdSequencerComponentImpl cmdSeq;
extern Svc::SocketGndIfImpl sockGndIf;
extern Svc::ConsoleTextLoggerImpl textLogger;
extern Svc::ActiveLoggerImpl eventLogger;
extern Svc::LinuxTimeImpl linuxTime;
extern Svc::LinuxTimerComponentImpl linuxTimer;
extern Svc::TlmChanImpl chanTlm;
extern Svc::CommandDispatcherImpl cmdDisp;
extern Svc::AssertFatalAdapterComponentImpl fatalAdapter;
extern Svc::FatalHandlerComponentImpl fatalHandler;

// i2c driver
extern Drv::LinuxI2cDriverComponentImpl i2cDrv;

// servo controllers
extern RobotArm::PcaServoComponentImpl clawServo;
extern RobotArm::PcaServoComponentImpl baseServo;
extern RobotArm::PcaServoComponentImpl armServo;
extern RobotArm::PcaServoComponentImpl clawTiltServo;

// arm demo component
extern RobotArm::ArmAppComponentImpl armDemo;

#endif

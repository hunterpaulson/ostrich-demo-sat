<title>ArmApplication Component Dictionary</title>
# ArmApplication Component Dictionary


## Command List

|Mnemonic|ID|Description|Arg Name|Arg Type|Comment
|---|---|---|---|---|---|
|AA_CLAW_ANG|0 (0x0)|Claw angle command| | |
| | | |angle|F32|The commanded angle|
|AA_BASE_ANG|1 (0x1)|Base angle command| | |
| | | |angle|F32|The commanded angle|
|AA_ARM_ANG|2 (0x2)|ARM angle command| | |
| | | |angle|F32|The commanded angle|
|AA_CLAW_TILT_ANG|3 (0x3)|Claw tilt angle command| | |
| | | |angle|F32|The commanded angle|

## Telemetry Channel List

|Channel Name|ID|Type|Description|
|---|---|---|---|
|AA_ClawAngle|0 (0x0)|F32|Commanded angle|
|AA_BaseAngle|1 (0x1)|F32|Commanded angle|
|AA_ArmAngle|2 (0x2)|F32|Commanded angle|
|AA_ClawTiltAngle|3 (0x3)|F32|Commanded angle|

## Event List

|Event Name|ID|Description|Arg Name|Arg Type|Arg Size|Description
|---|---|---|---|---|---|---|
|AA_ClawAngleCmd|0 (0x0)|Claw Angle commanded| | | | |
| | | |angle|F32||The commanded angle|
|AA_BaseAngleCmd|0 (0x0)|Base Angle commanded| | | | |
| | | |angle|F32||The commanded angle|
|AA_ArmAngleCmd|0 (0x0)|Arm Angle commanded| | | | |
| | | |angle|F32||The commanded angle|
|AA_ClawTiltAngleCmd|0 (0x0)|Claw tilt angle commanded| | | | |
| | | |angle|F32||The commanded angle|

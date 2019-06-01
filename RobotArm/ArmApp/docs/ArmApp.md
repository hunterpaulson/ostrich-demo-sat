<title>ArmApp Component Dictionary</title>
# ArmApp Component Dictionary


## Command List

|Mnemonic|ID|Description|Arg Name|Arg Type|Comment
|---|---|---|---|---|---|
|AA_CLAW_ANG|0 (0x0)|Claw angle command| | |
| | | |angle|F32|The commanded angle|
|AA_BASE_ANG|1 (0x1)|Base angle command| | |
| | | |angle|F32|The commanded angle|
|AA_ARM_HEIGHT_ANG|2 (0x2)|Arm height angle command| | |
| | | |angle|F32|The commanded angle|
|AA_ARM_LENGTH_ANG|3 (0x3)|Arm length angle command| | |
| | | |angle|F32|The commanded angle|

## Telemetry Channel List

|Channel Name|ID|Type|Description|
|---|---|---|---|
|AA_ClawAngle|0 (0x0)|F32|Commanded angle|
|AA_BaseAngle|1 (0x1)|F32|Commanded angle|
|AA_ArmHeightAngle|2 (0x2)|F32|Commanded angle|
|AA_ArmLengthAngle|3 (0x3)|F32|Commanded angle|
|AA_Cycles|4 (0x4)|U32|Scheduler cycles|

## Event List

|Event Name|ID|Description|Arg Name|Arg Type|Arg Size|Description
|---|---|---|---|---|---|---|
|AA_ClawAngleCmd|0 (0x0)|Claw Angle commanded| | | | |
| | | |angle|F32||The commanded angle|
|AA_BaseAngleCmd|1 (0x1)|Base Angle commanded| | | | |
| | | |angle|F32||The commanded angle|
|AA_ArmLengthAngleCmd|2 (0x2)|Arm length commanded| | | | |
| | | |angle|F32||The commanded angle|
|AA_ArmHeightAngleCmd|3 (0x3)|Arm height angle commanded| | | | |
| | | |angle|F32||The commanded angle|

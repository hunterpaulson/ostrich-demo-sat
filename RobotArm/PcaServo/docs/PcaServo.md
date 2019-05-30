<title>PcaServo Component Dictionary</title>
# PcaServo Component Dictionary


## Command List

|Mnemonic|ID|Description|Arg Name|Arg Type|Comment
|---|---|---|---|---|---|
|PS_ANG|0 (0x0)|Servo angle command| | |
| | | |angle|F32|The commanded angle|

## Telemetry Channel List

|Channel Name|ID|Type|Description|
|---|---|---|---|
|PS_Angle|0 (0x0)|F32|Commanded angle|
|PS_Reg|1 (0x1)|U16|Register value|

## Event List

|Event Name|ID|Description|Arg Name|Arg Type|Arg Size|Description
|---|---|---|---|---|---|---|
|PS_AngleCmd|0 (0x0)|Angle commanded| | | | |
| | | |inst|U8||The motor instance|
| | | |angle|F32||The commanded angle|
| | | |reg|U16||The register value|

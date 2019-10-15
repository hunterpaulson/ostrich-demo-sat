/*
 * PcaServoComponentImplCfg.hpp
 *
 *  Created on: May 29, 2019
 *      Author: tim
 */

#ifndef ROBOTARM_PCASERVO_PCASERVOCOMPONENTIMPLCFG_HPP_
#define ROBOTARM_PCASERVO_PCASERVOCOMPONENTIMPLCFG_HPP_

namespace RobotArm {
	const U32 I2C_BUFFER_SIZE = 8;
	const U32 SERVO_BRD_ADDR = 0x40;
//	const U16 MINUS_90 = 400;
//	const U16 PLUS_90 = 2100;
	const U16 MINUS_90 = 0x58;
	const U16 PLUS_90 = 0x1F9;
}



#endif /* ROBOTARM_PCASERVO_PCASERVOCOMPONENTIMPLCFG_HPP_ */

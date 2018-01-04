/*
 * PiServo.h
 *
 *  Created on: Jan 4, 2018
 *      Author: veit
 */

#ifndef SRC_PISERVO_H_
#define SRC_PISERVO_H_

class PiServo {
public:
	PiServo();

	void setRotation(int pulseWidth_uS);
};

#endif /* SRC_PISERVO_H_ */

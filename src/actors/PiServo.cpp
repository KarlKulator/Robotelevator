/*
 * PiServo.cpp
 *
 *  Created on: Jan 4, 2018
 *      Author: veit
 */

#include "PiServo.h"

#include <wiringPi.h>

PiServo::PiServo() {
	pinMode(18, PWM_OUTPUT);
	pwmSetMode (PWM_MODE_MS);
	pwmSetRange(2000);
	pwmSetClock(192);
}

void PiServo::setRotation(int pulseWidth_uS) {
	pwmWrite(18, pulseWidth_uS);
}

/*
 * ElevatorMotorServoswitch.cpp
 *
 *  Created on: Jan 3, 2018
 *      Author: veit
 */

#include "ServoswitchedElevatorMotor.h"
#include <wiringPi.h>

static const int moveDownFirstRotationPulseWidth_uS = 120;
static const int moveDownSecondRotationPulseWidth_uS = 140;

static const int moveUpFirstRotationPulseWidth_uS = 180;
static const int moveUpSecondRotationPulseWidth_uS = 170;

static const int stopRotationPulseWidth_uS = 155;

void ServoswitchedElevatorMotor::moveDown() {
	m_servoSwitch.setRotation(moveDownFirstRotationPulseWidth_uS);
	delay(300);
	m_servoSwitch.setRotation(moveDownSecondRotationPulseWidth_uS);
}

void ServoswitchedElevatorMotor::moveUp() {
	m_servoSwitch.setRotation(moveUpFirstRotationPulseWidth_uS);
	delay(300);
	m_servoSwitch.setRotation(moveUpSecondRotationPulseWidth_uS);
}

void ServoswitchedElevatorMotor::stop() {
	m_servoSwitch.setRotation(stopRotationPulseWidth_uS);
}

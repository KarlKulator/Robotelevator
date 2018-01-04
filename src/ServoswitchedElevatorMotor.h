/*
 * ElevatorMotorServoswitch.h
 *
 *  Created on: Jan 3, 2018
 *      Author: veit
 */

#ifndef SRC_SERVOSWITCHEDELEVATORMOTOR_H_
#define SRC_SERVOSWITCHEDELEVATORMOTOR_H_

#include "IElevatorMotor.h"
#include "PiServo.h"

class ServoswitchedElevatorMotor: public IElevatorMotor {
public:
	virtual ~ServoswitchedElevatorMotor() {};

	virtual void moveDown();
	virtual void moveUp();
	virtual void stop();

private:
	PiServo m_servoSwitch;
};

#endif /* SRC_SERVOSWITCHEDELEVATORMOTOR_H_ */

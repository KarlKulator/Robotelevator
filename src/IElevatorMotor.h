/*
 * ElevatorMotor.h
 *
 *  Created on: Jan 3, 2018
 *      Author: veit
 */

#ifndef SRC_MOTOR_ELEVATORMOTOR_H_
#define SRC_MOTOR_ELEVATORMOTOR_H_

class IElevatorMotor {
public:
	IElevatorMotor() {};
	virtual ~IElevatorMotor() {};
	
	virtual void moveDown() = 0;
	virtual void moveUp() = 0;
	virtual void stop() = 0;
};

#endif /* SRC_MOTOR_ELEVATORMOTOR_H_ */

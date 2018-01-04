/*
 * Buttons.h
 *
 *  Created on: Jan 3, 2018
 *      Author: veit
 */
#include "statemachine/RobotelevatorStatemachine.h"

#ifndef SRC_BUTTONS_H_
#define SRC_BUTTONS_H_

#include "Button.h"

class Buttons {
public:
	explicit Buttons(RobotelevatorStatemachine* robotElevatorStatemachine);

	void carrierButtonPressed2ndFloor();
	void carrierButtonPressed1stFloor();
	void carrierButtonPressedParkingPosition();
	void robotButtonPressed2ndFloor();
	void robotButtonPressed1stFloor();

	void carrierButtonReleased2ndFloor();
	void carrierButtonReleased1stFloor();
	void carrierButtonReleasedParkingPosition();
	void robotButtonReleased2ndFloor();
	void robotButtonReleased1stFloor();

private:
	RobotelevatorStatemachine* m_robotElevatorStatemachine;

	Button m_carrierButton2ndFloor;
	Button m_carrierButton1stFloor;
	Button m_carrierButtonParkingPosition;

	Button m_robotButton2ndFloor;
	Button m_robotButton1stFloor;
};

#endif /* SRC_BUTTONS_H_ */

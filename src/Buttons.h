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
	virtual ~Buttons();

	static void carrierButtonPressed2ndFloor();
	static void carrierButtonPressed1stFloor();
	static void carrierButtonPressedParkingPosition();
	static void robotButtonPressed2ndFloor();
	static void robotButtonPressed1stFloor();

	static void carrierButtonReleased2ndFloor();
	static void carrierButtonReleased1stFloor();
	static void carrierButtonReleasedParkingPosition();
	static void robotButtonReleased2ndFloor();
	static void robotButtonReleased1stFloor();

private:
	RobotelevatorStatemachine* m_robotElevatorStatemachine

	Button m_carrierButton2ndFloor;
	Button m_carrierButton1stFloor;
	Button m_carrierButtonParkingPosition;

	Button m_robotButton2ndFloor;
	Button m_robotButton1stFloor;
};

#endif /* SRC_BUTTONS_H_ */

/*
 * Buttons.cpp
 *
 *  Created on: Jan 3, 2018
 *      Author: veit
 */

#include "Buttons.h"

#include <wiringPi.h>
#include <thread>

Buttons::Buttons(RobotelevatorStatemachine* robotElevatorStatemachine) :
		m_robotElevatorStatemachine(robotElevatorStatemachine), m_carrierButton2ndFloor(
				10), m_carrierButton1stFloor(11), m_carrierButtonParkingPosition(
				12), m_robotButton2ndFloor(13), m_robotButton1stFloor(14) {
	auto buttonsStateChangePollingThread =
			std::thread(
					[=]() {
						while(true) {
							switch(m_carrierButton2ndFloor.updateAndReadButtonStateChange()) {
								case ButtonStateChange::eWasPressed:
								carrierButtonPressed2ndFloor();
								break;
								case ButtonStateChange::eWasReleased:
								carrierButtonReleased2ndFloor();
								break;
								default:
								break;
							}

							switch(m_carrierButton1stFloor.updateAndReadButtonStateChange()) {
								case ButtonStateChange::eWasPressed:
								carrierButtonPressed1stFloor();
								break;
								case ButtonStateChange::eWasReleased:
								carrierButtonReleased1stFloor();
								break;
								default:
								break;
							}

							switch(m_carrierButtonParkingPosition.updateAndReadButtonStateChange()) {
								case ButtonStateChange::eWasPressed:
								carrierButtonPressedParkingPosition();
								break;
								case ButtonStateChange::eWasReleased:
								carrierButtonReleasedParkingPosition();
								break;
								default:
								break;
							}

							switch(m_robotButton2ndFloor.updateAndReadButtonStateChange()) {
								case ButtonStateChange::eWasPressed:
								robotButtonPressed2ndFloor();
								break;
								case ButtonStateChange::eWasReleased:
								robotButtonReleased2ndFloor();
								break;
								default:
								break;
							}

							switch(m_robotButton1stFloor.updateAndReadButtonStateChange()) {
								case ButtonStateChange::eWasPressed:
								robotButtonPressed1stFloor();
								break;
								case ButtonStateChange::eWasReleased:
								robotButtonReleased1stFloor();
								break;
								default:
								break;
							}
							delay(50);
						}
					});

	buttonsStateChangePollingThread.detach();
}

void Buttons::carrierButtonPressed2ndFloor() {
	m_robotElevatorStatemachine->carrierButtonPressed2ndFloor();
}

void Buttons::carrierButtonPressed1stFloor() {
	m_robotElevatorStatemachine->carrierButtonPressed2ndFloor();
}

void Buttons::carrierButtonPressedParkingPosition() {
	m_robotElevatorStatemachine->carrierButtonPressedParkingPosition();
}

void Buttons::robotButtonPressed2ndFloor() {
	m_robotElevatorStatemachine->robotButtonPressed2ndFloor();
}

void Buttons::robotButtonPressed1stFloor() {
	m_robotElevatorStatemachine->robotButtonPressed1stFloor();
}

void Buttons::carrierButtonReleased2ndFloor() {
}

void Buttons::carrierButtonReleased1stFloor() {
}

void Buttons::carrierButtonReleasedParkingPosition() {
}

void Buttons::robotButtonReleased2ndFloor() {
	m_robotElevatorStatemachine->robotButtonReleased2ndFloor();
}

void Buttons::robotButtonReleased1stFloor() {
	m_robotElevatorStatemachine->robotButtonReleased1stFloor();
}

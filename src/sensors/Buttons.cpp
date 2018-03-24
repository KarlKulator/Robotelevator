/*
 * Buttons.cpp
 *
 *  Created on: Jan 3, 2018
 *      Author: veit
 */

#include "Buttons.h"

#include <wiringPi.h>
#include <thread>
#include <iostream>

Buttons::Buttons(RobotelevatorStatemachine* robotElevatorStatemachine) :
		m_robotElevatorStatemachine(robotElevatorStatemachine), m_carrierButton2ndFloor(
				22), m_carrierButton1stFloor(23), m_carrierButtonParkingPosition(
				24), m_robotButton2ndFloor(25), m_robotButton1stFloor(6) {
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
								case ButtonStateChange::eWasReleased:
								robotButtonPressed2ndFloor();
								break;
								case ButtonStateChange::eWasPressed:
								robotButtonReleased2ndFloor();
								break;
								default:
								break;
							}

							switch(m_robotButton1stFloor.updateAndReadButtonStateChange()) {
								case ButtonStateChange::eWasReleased:
								robotButtonPressed1stFloor();
								break;
								case ButtonStateChange::eWasPressed:
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
	std::cout << "carrierButtonPressed2ndFloor" << std::endl;
	m_robotElevatorStatemachine->carrierButtonPressed2ndFloor();
}

void Buttons::carrierButtonPressed1stFloor() {
	std::cout << "carrierButtonPressed1stFloor" << std::endl;

	m_robotElevatorStatemachine->carrierButtonPressed1stFloor();
}

void Buttons::carrierButtonPressedParkingPosition() {
	std::cout << "carrierButtonPressedParkingPosition" << std::endl;

	m_robotElevatorStatemachine->carrierButtonPressedParkingPosition();
}

void Buttons::robotButtonPressed2ndFloor() {
	std::cout << "robotButtonPressed2ndFloor" << std::endl;

	m_robotElevatorStatemachine->robotButtonPressed2ndFloor();
}

void Buttons::robotButtonPressed1stFloor() {
	std::cout << "robotButtonPressed1stFloor" << std::endl;

	m_robotElevatorStatemachine->robotButtonPressed1stFloor();
}

void Buttons::carrierButtonReleased2ndFloor() {
	std::cout << "carrierButtonReleased2ndFloor" << std::endl;

}

void Buttons::carrierButtonReleased1stFloor() {
	std::cout << "carrierButtonReleased1stFloor" << std::endl;

}

void Buttons::carrierButtonReleasedParkingPosition() {
	std::cout << "carrierButtonReleasedParkingPosition" << std::endl;

}

void Buttons::robotButtonReleased2ndFloor() {
	std::cout << "robotButtonReleased2ndFloor" << std::endl;

	m_robotElevatorStatemachine->robotButtonReleased2ndFloor();
}

void Buttons::robotButtonReleased1stFloor() {
	std::cout << "robotButtonReleased1stFloor" << std::endl;

	m_robotElevatorStatemachine->robotButtonReleased1stFloor();
}

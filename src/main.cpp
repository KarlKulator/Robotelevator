/*
 * main.cpp
 *
 *  Created on: Jan 4, 2018
 *      Author: veit
 */

#include <statemachine/RobotelevatorStatemachine.h>
#include <actors/ServoswitchedElevatorMotor.h>
#include <sensors/Buttons.h>
#include <timers/Timer.h>

#include <wiringPi.h>

#include <chrono>
#include <thread>
#include <iostream>

int main() {
	wiringPiSetupGpio();

	ServoswitchedElevatorMotor motor;
	Timer dockUndockTimer(10000);
	RobotelevatorStatemachine statemachine(&motor, &dockUndockTimer);
	Buttons buttons(&statemachine);

	statemachine.startCleanup();

	while (true) {
		if (statemachine.isExited()) {
            std::cout << "exited" << std::endl;
			return 0;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

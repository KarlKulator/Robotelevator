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
#include <string.h>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cout
				<< "Not enough arguments. First argument needs to specify floor to clean."
				<< std::endl;
        return 0;
	}

	wiringPiSetupGpio();

	ServoswitchedElevatorMotor motor;
	Timer dockUndockTimer(20000);
	RobotelevatorStatemachine statemachine(&motor, &dockUndockTimer);
	Buttons buttons(&statemachine);

	if (strcmp(argv[1], "2") == 0) {
		statemachine.startCleanupSecondFloor();

	} else if (strcmp(argv[1], "1") == 0) {
		statemachine.startCleanupFirstFloor();

	} else {
		std::cout << argv[1] << std::endl;
		std::cout << "Invalid arguments. First argument needs to specify floor to clean." << std::endl;
        return 0;
	}

	while (true) {
		if (statemachine.isExited()) {
			std::cout << "exited" << std::endl;
			return 0;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

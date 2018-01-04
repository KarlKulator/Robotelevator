/*
 * main.cpp
 *
 *  Created on: Jan 4, 2018
 *      Author: veit
 */

#include "statemachine/RobotelevatorStatemachine.h"
#include "ServoswitchedElevatorMotor.h"
#include "Buttons.h"

#include <chrono>
#include <thread>

int main(){
	ServoswitchedElevatorMotor motor;
	RobotelevatorStatemachine statemachine(&motor);
	Buttons buttons(&statemachine);

	statemachine.startCleanup();

	while(true)
	   std::this_thread::sleep_for(std::chrono::hours::max());
}



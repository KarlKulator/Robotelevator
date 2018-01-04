/*
 * RobotelevatorStatemachine.cpp
 *
 *  Created on: Jan 3, 2018
 *      Author: veit
 */

#include "RobotelevatorStatemachine.h"

#include <thread>
#include <chrono>
#include <functional>

RobotelevatorStatemachine::RobotelevatorStatemachine(
		IElevatorMotor* elevatorMotor, Timer* dockUndockTimer) :
		m_statemachineContext(*this), m_elevatorMotor(elevatorMotor), m_dockUndockTimer(
				dockUndockTimer) {
	m_statemachineContext.setDebugFlag(true);

}

void RobotelevatorStatemachine::moveDown() {
	m_elevatorMotor->moveDown();
}

void RobotelevatorStatemachine::moveUp() {
	m_elevatorMotor->moveUp();
}

void RobotelevatorStatemachine::stop() {
	m_elevatorMotor->stop();
}

void RobotelevatorStatemachine::startUndockingTimer() {
	m_currentUndockingTimerId = m_nextUndockingTimerId;
	++m_nextUndockingTimerId;

	m_dockUndockTimer->startTimer(m_currentUndockingTimerId,
			std::bind(&RobotelevatorStatemachine::undockingTimePassed, this, std::placeholders::_1));
}

void RobotelevatorStatemachine::cancelUndockingTimer() {
	m_currentUndockingTimerId = -1;
}

void RobotelevatorStatemachine::startDockingTimer() {
	m_currentDockingTimerId = m_nextDockingTimerId;
	++m_nextDockingTimerId;

	m_dockUndockTimer->startTimer(m_currentDockingTimerId,
				std::bind(&RobotelevatorStatemachine::dockingTimePassed, this, std::placeholders::_1));
}

void RobotelevatorStatemachine::cancelDockingTimer() {
	m_currentDockingTimerId = -1;
}

void RobotelevatorStatemachine::exit() {
	m_isExited = true;
}

void RobotelevatorStatemachine::carrierButtonPressed1stFloor() {
	std::lock_guard<std::mutex> lockGuard(m_incomingEventSequentialisingMutex);
	m_statemachineContext.carrierButtonPressed1stFloor();
}

void RobotelevatorStatemachine::carrierButtonPressed2ndFloor() {
	std::lock_guard<std::mutex> lockGuard(m_incomingEventSequentialisingMutex);
	m_statemachineContext.carrierButtonPressed2ndFloor();
}

void RobotelevatorStatemachine::carrierButtonPressedParkingPosition() {
	std::lock_guard<std::mutex> lockGuard(m_incomingEventSequentialisingMutex);
	m_statemachineContext.carrierButtonPressedParkingPosition();
}

void RobotelevatorStatemachine::dockingTimePassed(int timerId) {
	std::lock_guard<std::mutex> lockGuard(m_incomingEventSequentialisingMutex);
	m_statemachineContext.dockingTimePassed(timerId);
}

void RobotelevatorStatemachine::robotButtonPressed1stFloor() {
	std::lock_guard<std::mutex> lockGuard(m_incomingEventSequentialisingMutex);
	m_statemachineContext.robotButtonPressed1stFloor();
}

void RobotelevatorStatemachine::robotButtonPressed2ndFloor() {
	std::lock_guard<std::mutex> lockGuard(m_incomingEventSequentialisingMutex);
	m_statemachineContext.robotButtonPressed2ndFloor();
}

void RobotelevatorStatemachine::robotButtonReleased1stFloor() {
	std::lock_guard<std::mutex> lockGuard(m_incomingEventSequentialisingMutex);
	m_statemachineContext.robotButtonReleased1stFloor();
}

void RobotelevatorStatemachine::robotButtonReleased2ndFloor() {
	std::lock_guard<std::mutex> lockGuard(m_incomingEventSequentialisingMutex);
	m_statemachineContext.robotButtonReleased2ndFloor();
}

void RobotelevatorStatemachine::startCleanup() {
	std::lock_guard<std::mutex> lockGuard(m_incomingEventSequentialisingMutex);
	m_statemachineContext.startCleanup();
}

void RobotelevatorStatemachine::undockingTimePassed(int timerId) {
	std::lock_guard<std::mutex> lockGuard(m_incomingEventSequentialisingMutex);
	m_statemachineContext.undockingTimePassed(timerId);
}


/*
 * RobotelevatorStatemachine.h
 *
 *  Created on: Jan 3, 2018
 *      Author: veit
 */

#ifndef SRC_STATEMACHINE_ROBOTELEVATORSTATEMACHINE_H_
#define SRC_STATEMACHINE_ROBOTELEVATORSTATEMACHINE_H_

#include "RobotelevatorStatemachine_sm.h"
#include <actors/IElevatorMotor.h>
#include <timers/Timer.h>
#include <mutex>

class RobotelevatorStatemachine {
public:
	explicit RobotelevatorStatemachine(IElevatorMotor* elevatorMotor, Timer* dockUndockTimer);
	virtual ~RobotelevatorStatemachine() {
	}

	void moveDown();
	void moveUp();
	void stop();
	void startUndockingTimer();
	void cancelUndockingTimer();
	void startDockingTimer();
	void cancelDockingTimer();
	void exit();

	void carrierButtonPressed1stFloor();
	void carrierButtonPressed2ndFloor();
	void carrierButtonPressedParkingPosition();
	void dockingTimePassed(int timerId);
	void robotButtonPressed1stFloor();
	void robotButtonPressed2ndFloor();
	void robotButtonReleased1stFloor();
	void robotButtonReleased2ndFloor();
	void startCleanupFirstFloor();
	void startCleanupSecondFloor();
	void undockingTimePassed(int timerId);

	int getCurrentUndockingTimerId() {
		return m_currentUndockingTimerId;
	}
	int getCurrentDockingTimerId() {
		return m_currentDockingTimerId;
	}

	bool isExited(){
		return m_isExited;
	}

private:
	RobotelevatorStatemachineContext m_statemachineContext;
	std::mutex m_incomingEventSequentialisingMutex;

	IElevatorMotor* m_elevatorMotor;
	Timer* m_dockUndockTimer;

	int m_nextUndockingTimerId = 0;
	int m_nextDockingTimerId = 0;

	int m_currentUndockingTimerId = -1;
	int m_currentDockingTimerId = -1;

	bool m_isExited = false;

};

#endif /* SRC_STATEMACHINE_ROBOTELEVATORSTATEMACHINE_H_ */

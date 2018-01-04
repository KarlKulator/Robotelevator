/*
 * Timer.h
 *
 *  Created on: Jan 4, 2018
 *      Author: veit
 */

#ifndef SRC_TIMER_H_
#define SRC_TIMER_H_

#include <functional>

class Timer {
public:
	explicit Timer(unsigned int timeout_ms);
	virtual ~Timer();

	void startTimer(int currentStartId, std::function<void( int )> timerFinishedCallback);

private:
	const int m_timeout_ms;
};

#endif /* SRC_TIMER_H_ */

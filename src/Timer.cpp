/*
 * Timer.cpp
 *
 *  Created on: Jan 4, 2018
 *      Author: veit
 */

#include "Timer.h"

#include <thread>
#include <chrono>

Timer::Timer(unsigned int timeout_ms):m_timeout_ms(timeout_ms) {
}

Timer::~Timer() {
	// TODO Auto-generated destructor stub
}

void Timer::startTimer(int currentStartId, std::function<void( int )> timerFinishedCallback) {
	std::thread([=](){
		std::this_thread::sleep_for(std::chrono::seconds(m_timeout_ms));
		timerFinishedCallback(currentStartId);
    });
}

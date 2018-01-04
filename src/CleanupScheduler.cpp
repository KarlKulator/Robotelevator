/*
 * CleanupScheduler.cpp
 *
 *  Created on: Jan 4, 2018
 *      Author: veit
 */

#include "CleanupScheduler.h"

#include <thread>
#include <time.h>
#include <iostream>

CleanupScheduler::CleanupScheduler() {

	std::thread([=]() {
		time_t rawtime;
		struct tm *info;
		char buffer[100];
		time(&rawtime);
		info = localtime(&rawtime);
		strftime(buffer, sizeof(buffer), "%A", info);
		std::cout <<  "Current weekday:" << buffer << std::endl;
	}).detach();

}

CleanupScheduler::~CleanupScheduler() {
	// TODO Auto-generated destructor stub
}


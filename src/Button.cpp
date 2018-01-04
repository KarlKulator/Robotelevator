/*
 * Button.cpp
 *
 *  Created on: Jan 4, 2018
 *      Author: veit
 */

#include "Button.h"

#include <wiringPi.h>

Button::Button(unsigned int broadcomPinId) : m_broadcomPinId(broadcomPinId){
	pinMode(m_broadcomPinId, INPUT);
	pullUpDnControl(m_broadcomPinId, PUD_UP);
	m_isPressed = digitalRead(m_broadcomPinId);
}

ButtonStateChange Button::updateAndReadButtonStateChange() {
	bool isCurrentlyPressed  = digitalRead(m_broadcomPinId);
	if(isCurrentlyPressed != m_isPressed){
		m_isPressed = isCurrentlyPressed;
		return m_isPressed ? ButtonStateChange::eWasPressed : ButtonStateChange::eWasReleased;
	}else{
		return ButtonStateChange::eNoChange;
	}
}

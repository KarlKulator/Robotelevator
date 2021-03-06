/*
 * Button.cpp
 *
 *  Created on: Jan 4, 2018
 *      Author: veit
 */

#include "Button.h"

#include <wiringPi.h>

Button::Button(unsigned int broadcomPinId, unsigned int neededChangeCount) : m_broadcomPinId(broadcomPinId), m_neededChangeCount(neededChangeCount){
	pinMode(m_broadcomPinId, INPUT);
	pullUpDnControl(m_broadcomPinId, PUD_DOWN);
	m_isPressed = digitalRead(m_broadcomPinId);
}

ButtonStateChange Button::updateAndReadButtonStateChange() {
	bool isCurrentlyPressed  = digitalRead(m_broadcomPinId);
	if(isCurrentlyPressed != m_isPressed){
        ++m_changeCount;
        if(m_changeCount > m_neededChangeCount){
            m_changeCount = 0;
            m_isPressed = isCurrentlyPressed;
            return m_isPressed ? ButtonStateChange::eWasPressed : ButtonStateChange::eWasReleased;
        }
	}else{
        m_changeCount = 0;
		return ButtonStateChange::eNoChange;
	}
}

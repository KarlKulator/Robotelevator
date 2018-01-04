/*
 * Button.h
 *
 *  Created on: Jan 4, 2018
 *      Author: veit
 */

#ifndef SRC_BUTTON_H_
#define SRC_BUTTON_H_

enum class ButtonStateChange{
	eWasPressed, eWasReleased, eNoChange
};

class Button {
public:
	Button(unsigned int broadcomPinId);
	virtual ~Button() {};

	ButtonStateChange updateAndReadButtonStateChange();

private:
	unsigned int m_broadcomPinId;
	bool m_isPressed = 0;
};

#endif /* SRC_BUTTON_H_ */

#ifndef OI_H
#define OI_H
#include "WPILib.h"

class OI {
private:
	Joystick* leftStick;
	Joystick* rightStick;

public:
	OI();
	Joystick* getLeftStick();
	Joystick* getRightStick();
};

#endif  // OI_H

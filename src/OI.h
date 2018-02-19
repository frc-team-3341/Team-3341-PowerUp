#ifndef OI_H
#define OI_H
#include "WPILib.h"

class OI {
private:
	Joystick* leftStick;
	Joystick* rightStick;
	Joystick* armStick;

	Button* armMax;
	Button* armMin;
public:
	OI();
	Joystick* getLeftStick();
	Joystick* getRightStick();
	Joystick* getArmStick();
};

#endif  // OI_H

#ifndef OI_H
#define OI_H

#include <WPILib.h>

#include <iostream>

class OI {
private:
	Joystick* leftStick;
	Joystick* rightStick;
	Joystick* liftStick;

	Button* shootCrate;
	Button* getCrate;
	Button* testButton;
	Button* calibrateLift;
	Button* positionPidTest;

	Joystick* armStick;

	Joystick* liftStick;

	Button* armMax;
	Button* armMin;
	Button* armToggle;
public:
	OI();
	Joystick* getLeftStick();
	Joystick* getRightStick();

	Joystick* getArmStick();

	Joystick* getLiftStick();

};

#endif  // OI_H

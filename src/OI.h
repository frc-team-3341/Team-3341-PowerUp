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

public:
	OI();
	Joystick* getLeftStick();
	Joystick* getRightStick();
	Joystick* getLiftStick();

};

#endif  // OI_H

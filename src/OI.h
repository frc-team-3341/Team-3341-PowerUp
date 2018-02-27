#ifndef OI_H
#define OI_H
#include "WPILib.h"

class OI {
private:
	Joystick* leftStick;
	Joystick* rightStick;

	Joystick* armStick;

	Joystick* liftStick;
	XboxController* xbox;

	Button* shootCrate;
	Button* getCrate;
	Button* testButton;
	Button* calibrateLift;

	Button* liftPositionPID;

	Button* armMax;
	Button* armMin;
	Button* armToggle;
public:
	OI();
	Joystick* getLeftStick();
	Joystick* getRightStick();

	Joystick* getArmStick();

	Joystick* getLiftStick();
	XboxController* getXbox();

};

#endif  // OI_H

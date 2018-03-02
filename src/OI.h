#ifndef OI_H
#define OI_H
#include "WPILib.h"

class OI {
private:
	Joystick* leftStick;
	Joystick* rightStick;

	Joystick* armStick;

	Joystick* liftStick;

	Button* shootCrate;
	Button* getCrate;
	Button* testButton;
	Button* calibrateLift;

	Button* cameraLeft;
	Button* cameraRight;
	//Button* liftPositionPID;




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

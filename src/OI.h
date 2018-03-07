#ifndef OI_H
#define OI_H
#include "WPILib.h"

class OI {
private:
	Joystick* leftStick;
	Joystick* rightStick;
	Joystick* armStick;
	Joystick* liftStick;

	//Arm buttons
	Button* shootCrate;
	Button* getCrate;
	Button* getCrateRight;
	Button* getCrateLeft;
	Button* armMax;
	Button* armMin;

	//Lift buttons
	Button* exchangeHeight;
	Button* testFullHeight;

	//Camera buttons
	Button* cameraLeft;
	Button* cameraRight;
	Button* armToggle;
public:
	OI();
	Joystick* getLeftStick();
	Joystick* getRightStick();
	Joystick* getArmStick();
	Joystick* getLiftStick();

	void ArmButtonsInit();
	void LiftButtonsInit();

};

#endif  // OI_H

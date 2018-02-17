#ifndef OI_H
#define OI_H
#include "WPILib.h"
#include "RobotMap.h"

class OI {
private:
	Joystick* leftStick;
	Joystick* rightStick;

	Joystick* liftStick;
	Button* testButton;
	Button* calibrateLift;

    void catherButtons(void);
public:
	OI();
	Joystick* getLeftStick();
	Joystick* getRightStick();

	Joystick* getLiftStick();

};

#endif  // OI_H

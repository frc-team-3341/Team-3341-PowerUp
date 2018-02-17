#ifndef OI_H
#define OI_H
#include "WPILib.h"
#include "Commands/AcquireCrate.h"
#include "Commands/ReleaseCrate.h"
#include "Commands/StopCatcher.h"

class OI {
private:
	Joystick* leftStick;
	Joystick* rightStick;
	Button* shootCrate;
	Button* getCrate;

public:
	OI();
	Joystick* getLeftStick();
	Joystick* getRightStick();
};

#endif  // OI_H

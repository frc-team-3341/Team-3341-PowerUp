#include "OI.h"

#include <WPILib.h>

OI::OI() : leftStick(new Joystick(LEFTMOTOR)),
rightStick(new Joystick(RIGHTMOTOR)),
liftStick(new Joystick(LIFT_MOTOR))
{
	// Process operator interface input here.
}

Joystick* OI::getLeftStick()
{
	return leftStick;
}

Joystick* OI::getRightStick()
{
	return rightStick;
}

Joystick* OI::getLiftStick()
{
	return liftStick;
}

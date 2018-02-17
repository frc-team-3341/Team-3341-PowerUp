#include "OI.h"

#include "Joystick.h"

OI::OI()
:leftStick(new Joystick(LEFT_JOY_PORT)), rightStick(new Joystick(RIGHT_JOY_PORT))
{
	// Process operator interface input here.
}

OI::~OI()
{
	delete leftStick;
	delete rightStick;
}

Joystick * OI::getLeftJoy()
{
	return leftStick;
}

Joystick * OI::getRightJoy()
{
	return rightStick;
}

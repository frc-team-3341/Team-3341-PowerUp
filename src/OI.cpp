#include "OI.h"

#include <WPILib.h>

OI::OI() : leftStick(new Joystick(0)), rightStick(new Joystick(1))
{
	shootCrate = new JoystickButton(leftStick, 1);
		shootCrate->WhenPressed(new ReleaseCrate());
		shootCrate->WhenReleased(new StopCatcher());


		getCrate = new JoystickButton(leftStick, 2);
		getCrate->WhenPressed(new AcquireCrate());
		getCrate->WhenReleased(new StopCatcher());

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

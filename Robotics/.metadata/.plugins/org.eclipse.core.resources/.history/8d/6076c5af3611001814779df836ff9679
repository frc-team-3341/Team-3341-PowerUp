#include "OI.h"
#include "Commands/AcquireCrate.h"
#include "Commands/StopCatcher.h"
#include "Commands/ReleaseCrate.h"


#include <WPILib.h>

OI::OI() : leftStick(new Joystick(LEFTMOTOR)),
rightStick(new Joystick(RIGHTMOTOR))
{
	catcherButtons();
	// Process operator interface input here.

}



OI::catcherButtons()
{
	shootCrate = new JoystickButton(leftStick, 1);
	shootCrate->WhenPressed(new ReleaseCrate());
	shootCrate->WhenReleased(new StopCatcher());


	getCrate = new JoystickButton(leftStick, 2);
	getBall2->WhenPressed(new AcquireCrate());
	getBall2->WhenReleased(new StopCatcher());

}
Joystick* OI::getLeftStick()
{
	return leftStick;
}

Joystick* OI::getRightStick()
{
	return rightStick;
}

Joystick* OI::getOperatorStick()
{
	return operatorStick;
}


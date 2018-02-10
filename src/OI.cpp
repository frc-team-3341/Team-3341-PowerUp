#include "OI.h"

#include <WPILib.h>
#include "Commands/MoveLiftToHeight.h"
#include "Commands/LiftPositionControl.h"

OI::OI() : leftStick(new Joystick(0)),
rightStick(new Joystick(1)),
liftStick(new Joystick(2))
{
	testButton = new JoystickButton(liftStick,2);
	liftPidButton = new JoystickButton(liftStick,1);
	testButton->WhenPressed(new MoveLiftToHeight(4));
	liftPidButton->WhenPressed(new LiftPositionControl());
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

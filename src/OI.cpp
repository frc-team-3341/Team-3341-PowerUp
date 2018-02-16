#include "OI.h"

#include <WPILib.h>
#include "Commands/MoveLiftToHeight.h"
#include "Commands/LiftPositionControl.h"
#include "Commands/MoveLiftToMinHeight.h"

OI::OI() : leftStick(new Joystick(0)),
rightStick(new Joystick(1)),
liftStick(new Joystick(2))
{
	testButton = new JoystickButton(liftStick,1);
	calibrateLift = new JoystickButton(liftStick,3);
	testButton->WhenPressed(new MoveLiftToHeight(4));
	calibrateLift->WhenPressed(new MoveLiftToMinHeight());
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

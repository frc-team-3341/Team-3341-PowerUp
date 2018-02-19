#include "OI.h"

#include "WPILib.h"
#include "Joystick.h"

//#include "Commands/ArmMax.h"
//#include "Commands/ArmMin.h"

OI::OI() : leftStick(new Joystick(0)), rightStick(new Joystick(1)), armStick(new Joystick(2))
			//armMax(new JoystickButton(armStick, 0)), armMin(new JoystickButton(armStick, 1))
{
	// Process operator interface input here.
	//armMax->WhenPressed(new ArmMax());
	//armMin->WhenPressed(new ArmMin());
}

Joystick* OI::getLeftStick()
{
	return leftStick;
}

Joystick* OI::getRightStick() {
	return rightStick;
}

Joystick* OI::getArmStick() {
	return armStick;
}

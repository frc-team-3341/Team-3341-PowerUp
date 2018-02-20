#include "OI.h"

#include "WPILib.h"
#include "Joystick.h"
#include "Commands/ArmPositionPID.h"
#include "Commands/ArmSpeedPID.h"
#include "Commands/ArmMin.h"
#include "Commands/TestReset.h"
#include "Commands/AutoArmMove.h"

//#include "Commands/ArmMax.h"
//#include "Commands/ArmMin.h"

OI::OI() : leftStick(new Joystick(0)), rightStick(new Joystick(1)), armStick(new Joystick(2)),
armToggle(new JoystickButton(armStick, 1)), armMin(new JoystickButton(armStick, 3)),
armMax(new JoystickButton(armStick, 7))
			//armMax(new JoystickButton(armStick, 0)), armMin(new JoystickButton(armStick, 1))
{
	// Process operator interface input here.
	//armMax->WhenPressed(new ArmMax());
	//armMin->WhenPressed(new ArmMin());
	armToggle->WhenPressed(new ArmPositionPID());
	armToggle->WhenReleased(new ArmSpeedPID());

	armMin->ToggleWhenPressed(new ArmMin());

	armMin->WhenReleased(new ArmSpeedPID());

	armMax->ToggleWhenPressed(new AutoArmMove(50)); //degrees
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

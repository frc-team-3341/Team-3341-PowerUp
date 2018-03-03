#include "OI.h"
#include "Commands/AcquireCrate.h"
#include "Commands/ReleaseCrate.h"
#include "Commands/StopCatcher.h"
#include <WPILib.h>
#include "Commands/MoveLiftToHeight.h"
#include "Commands/LiftPositionControl.h"
#include "Commands/MoveLiftToMinHeight.h"
#include "Commands/ArmPositionPID.h"
#include "Commands/ArmSpeedPID.h"
#include "Commands/ArmMin.h"
#include "Commands/AutoArmMove.h"
#include "Commands/moveCameraLeft.h"
#include "Commands/moveCameraRight.h"

OI::OI() : leftStick(new Joystick(0)),
rightStick(new Joystick(1)),
liftStick(new Joystick(3)), armStick(new Joystick(2)),

armToggle(new JoystickButton(armStick, 1)), armMin(new JoystickButton(armStick, 9)),
armMax(new JoystickButton(armStick, 7)), cameraLeft(new JoystickButton(leftStick, 2)),
cameraRight(new JoystickButton(rightStick, 2))
{
		shootCrate = new JoystickButton(armStick, 3);
		shootCrate->WhenPressed(new ReleaseCrate());
		shootCrate->WhenReleased(new StopCatcher());


		cameraLeft->WhenPressed(new moveCameraLeft());
		cameraRight->WhenPressed(new moveCameraRight());

		getCrate = new JoystickButton(armStick, 4);
		getCrate->WhenPressed(new AcquireCrate());
		getCrate->WhenReleased(new StopCatcher());

	// Process operator interface input here.

	//armMax->WhenPressed(new ArmMax());
	//armMin->WhenPressed(new ArmMin());
	armToggle->WhenPressed(new ArmPositionPID());
	armToggle->WhenReleased(new ArmSpeedPID());

	armMin->ToggleWhenPressed(new ArmMin());

	armMin->WhenReleased(new ArmSpeedPID());

	//armMax->WhenPressed(new TestReset());

	testButton = new JoystickButton(liftStick,1);
	calibrateLift = new JoystickButton(liftStick,3);
	testButton->WhenPressed(new MoveLiftToHeight(10));
	calibrateLift->WhenPressed(new MoveLiftToMinHeight());

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

Joystick* OI::getLiftStick()
{
	return liftStick;
}



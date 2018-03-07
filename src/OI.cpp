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
#include "Commands/TestReset.h"
#include "Commands/AutoArmMove.h"
#include "Commands/moveCameraLeft.h"
#include "Commands/moveCameraRight.h"
#include "Commands/ResetLiftEnc.h"
#include "Commands/TurnCubeLeft.h"
#include "Commands/TurnCubeRight.h"
#include "Commands/HoldRelease.h"
#include "Commands/HoldAcquire.h"

OI::OI() : leftStick(new Joystick(0)),
rightStick(new Joystick(1)),
armStick(new Joystick(2)),
liftStick(new Joystick(3)),

cameraLeft(new JoystickButton(leftStick, 2)),
cameraRight(new JoystickButton(rightStick, 2))
{
	ArmButtonsInit();
	LiftButtonsInit();

	//cameraLeft->WhenPressed(new moveCameraLeft());
	//cameraRight->WhenPressed(new moveCameraRight());
}

void OI::ArmButtonsInit()
{
	armToggle = new JoystickButton(armStick, 1);
	armToggle->WhenPressed(new ArmPositionPID());
	armToggle->WhenReleased(new ArmSpeedPID());

	shootCrate = new JoystickButton(armStick, 3);
	shootCrate->WhenPressed(new HoldAcquire());
	shootCrate->WhenReleased(new StopCatcher());

	getCrate = new JoystickButton(armStick, 4);
	getCrate->WhenPressed(new HoldRelease());
	getCrate->WhenReleased(new StopCatcher());

	getCrateLeft = new JoystickButton(armStick,5);
	getCrateLeft->WhenPressed(new TurnCubeLeft());
	getCrateLeft->WhenReleased(new StopCatcher());

	getCrateRight = new JoystickButton(armStick,6);
	getCrateRight->WhenPressed(new TurnCubeRight());
	getCrateRight->WhenReleased(new StopCatcher());

	armMax = new JoystickButton(armStick, 7);
	armMax->ToggleWhenPressed(new AutoArmMove(50)); //degrees
	//armMax->WhenPressed(new ArmMax());
	//armMin->WhenPressed(new ArmMin());
	//armMax->WhenPressed(new TestReset());

	armMin = new JoystickButton(armStick, 9);
	armMin->ToggleWhenPressed(new ArmMin());
	//armMin->WhenReleased(new ArmSpeedPID());
}

void OI::LiftButtonsInit()
{
	exchangeHeight = new JoystickButton(liftStick,5);
	exchangeHeight->WhenPressed(new MoveLiftToHeight(22));

	testFullHeight = new JoystickButton(liftStick,3);
	testFullHeight->WhenPressed(new MoveLiftToHeight(40));
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

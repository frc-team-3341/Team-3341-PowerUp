/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <WPILib.h>

OI::OI()
:joystickLeft(new Joystick(12)), joystickRight(new Joystick(13))
{
	// Process operator interface input here.
}

OI::~OI()
{
	delete joystickLeft;
	delete joystickRight;
	//delete getJoystickLeft;
	//delete getJoystickRight;
}

Joystick * OI::getJoystickLeft()
{
	return joystickLeft;
}

Joystick * OI::getJoystickRight()
{
	return joystickRight;
}

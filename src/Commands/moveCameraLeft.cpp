/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/moveCameraLeft.h"

moveCameraLeft::moveCameraLeft() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(camera);

}

// Called just before this Command runs the first time
void moveCameraLeft::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void moveCameraLeft::Execute() {

	//camera->moveLeft();
	std::cout << "Camera Position ----------" << camera->getServoPosition() << std::endl;
}

// Make this return true when this Command no longer needs to run execute()
bool moveCameraLeft::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void moveCameraLeft::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void moveCameraLeft::Interrupted() {

}

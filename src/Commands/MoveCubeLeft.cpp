/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "MoveCubeLeft.h"

MoveCubeLeft::MoveCubeLeft() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(catcher);
}

// Called just before this Command runs the first time
void MoveCubeLeft::Initialize() {
	catcher->moveLeft(0.75, catcher->Direction::in);
	catcher->moveRight(0, catcher->Direction::out);
}

// Called repeatedly when this Command is scheduled to run
void MoveCubeLeft::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool MoveCubeLeft::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MoveCubeLeft::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveCubeLeft::Interrupted() {

}

/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "ResetLiftEnc.h"

ResetLiftEnc::ResetLiftEnc(double timeout) :
timer(0)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(lift);
	timer = timeout;
}

// Called just before this Command runs the first time
void ResetLiftEnc::Initialize() {
	SetTimeout(timer);
}

// Called repeatedly when this Command is scheduled to run
void ResetLiftEnc::Execute() {
	lift->resetEncoder();
}

// Make this return true when this Command no longer needs to run execute()
bool ResetLiftEnc::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void ResetLiftEnc::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetLiftEnc::Interrupted() {

}

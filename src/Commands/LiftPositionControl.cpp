#include "LiftPositionControl.h"

LiftPositionControl::LiftPositionControl() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(lift);
}

// Called just before this Command runs the first time
void LiftPositionControl::Initialize() {
	lift->RobotSetClosedPositionLoop(lift->getMotor());
}

// Called repeatedly when this Command is scheduled to run
void LiftPositionControl::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool LiftPositionControl::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void LiftPositionControl::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftPositionControl::Interrupted() {

}

#include "MoveLift.h"

MoveLift::MoveLift() : liftVal(0)
{
	Requires(lift);
}

// Called just before this Command runs the first time
void MoveLift::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void MoveLift::Execute() {
	liftVal = oi->getLiftStick()->GetY();
	if (fabs(liftVal) < 0.05)
		liftVal = 0;
	//TODO: Add limit function for the actual mechanism but it is omitted for testing
	lift->move(liftVal);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveLift::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MoveLift::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveLift::Interrupted() {

}


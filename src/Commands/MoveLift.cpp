#include "MoveLift.h"

MoveLift::MoveLift(double height) {
	Requires(lift);
	liftHeight = height;
}

// Called just before this Command runs the first time
void MoveLift::Initialize() {
	liftHeight = 0;
}

// Called repeatedly when this Command is scheduled to run
void MoveLift::Execute() {
	lift->move(1);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveLift::IsFinished() {
	if(lift->getHeight() == liftHeight)
		return true;
	else
		return false;
}

// Called once after isFinished returns true
void MoveLift::End() {
	liftHeight = 0;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveLift::Interrupted() {

}

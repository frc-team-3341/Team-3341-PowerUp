#include "MoveLiftToMaxHeight.h"

MoveLiftToMaxHeight::MoveLiftToMaxHeight() {
	Requires(lift);
}

// Called just before this Command runs the first time
void MoveLiftToMaxHeight::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void MoveLiftToMaxHeight::Execute() {
	lift->move(1);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveLiftToMaxHeight::IsFinished() {
	if(lift->getHeight() == 72)
		return true;
	else
		return false;
}

// Called once after isFinished returns true
void MoveLiftToMaxHeight::End() {
	lift->move(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveLiftToMaxHeight::Interrupted() {

}

#include "MoveLiftToMinHeight.h"

MoveLiftToMinHeight::MoveLiftToMinHeight() {
	Requires(lift);
}

// Called just before this Command runs the first time
void MoveLiftToMinHeight::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void MoveLiftToMinHeight::Execute() {
	lift->getMotor()->SetInverted(true);
	lift->move(1);
}

// Make this return true when this Command no longer needs to run execute()
bool MoveLiftToMinHeight::IsFinished() {
	if(lift->getHeight() == 0)
			return true;
		else
			return false;
}

// Called once after isFinished returns true
void MoveLiftToMinHeight::End() {
	lift->move(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveLiftToMinHeight::Interrupted() {

}

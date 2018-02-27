#include "MoveLiftToMinHeight.h"

MoveLiftToMinHeight::MoveLiftToMinHeight() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(lift);
}

// Called just before this Command runs the first time
void MoveLiftToMinHeight::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void MoveLiftToMinHeight::Execute() {
	lift->move(lift->Limit(-0.4, 0.5));
}

// Make this return true when this Command no longer needs to run execute()
bool MoveLiftToMinHeight::IsFinished() {
	if(lift->getMotor()->GetSensorCollection().IsRevLimitSwitchClosed())
	{
		std::cout << "MoveLiftToMinHeightFinished" << std::endl;
		return true;
	}
	else
		return false;
}

// Called once after isFinished returns true
void MoveLiftToMinHeight::End() {
	lift->resetEncoder();
	lift->move(0);
	lift->setHeight(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveLiftToMinHeight::Interrupted() {

}

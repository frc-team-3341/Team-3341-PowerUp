#include "MoveLiftToMinHeight.h"
#include <iostream>

using namespace frc;

MoveLiftToMinHeight::MoveLiftToMinHeight()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(lift);
	std::cout << "MoveLiftToMinHeight started" << std::endl;
}

// Called just before this Command runs the first time
void MoveLiftToMinHeight::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void MoveLiftToMinHeight::Execute() {
	//tempPos = lift->getPosition();
	lift->move(-0.2);
	std::cout << "moving lift" << std::endl;
	//std::cout << "sensor velocity" << lift->getMotor()->GetSelectedSensorVelocity(0) << std::endl;
	//std::cout << "rev limit switch triggered?" << lift->getMotor()->GetSensorCollection().IsRevLimitSwitchClosed() << std::endl;
	//std::cout << "fwd limit switch triggered?" << lift->getMotor()->GetSensorCollection().IsFwdLimitSwitchClosed() << std::endl;
}

// Make this return true when this Command no longer needs to run execute()
bool MoveLiftToMinHeight::IsFinished() {
	if(lift->getMotor()->GetSensorCollection().IsRevLimitSwitchClosed())
	{
		std::cout << "FINISHEDDDDDDDDDDDDDDDDDDDDDDDDDDDDD" << std::endl;
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

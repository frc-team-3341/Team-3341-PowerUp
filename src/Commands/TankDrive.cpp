#include "TankDrive.h"

TankDrive::TankDrive() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drive);

}

// Called just before this Command runs the first time
void TankDrive::Initialize() {
	drive->resetEncoders();
}

// Called repeatedly when this Command is scheduled to run

void TankDrive::Execute() {
	drive->tankDrive(-oi->getLeftStick()->GetY(), -oi->getRightStick()->GetY());
	double average = (drive->leftDistance() + drive->rightDistance()) / 2;
	//std::cout << drive->getAngle() << std::endl;
}

// Make this return true when this Command no longer needs to run execute()
bool TankDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TankDrive::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TankDrive::Interrupted() {

}

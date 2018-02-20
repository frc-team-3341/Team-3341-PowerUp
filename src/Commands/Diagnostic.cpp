#include "Diagnostic.h"


Diagnostic::Diagnostic() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void Diagnostic::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Diagnostic::Execute()
{
	SmartDashboard::PutNumber("Left Wheel Speed", drive->leftSpeed());
	SmartDashboard::PutNumber("Right Wheel Speed", drive->rightSpeed());
	SmartDashboard::PutNumber("Gyro Angle", drive->getAngle());
	double leftWheelSpeed = SmartDashboard::GetData("Left Wheel Speed");
	double rightWheelSpeed = SmartDashboard::GetData("Right Wheel Speed");

	drive->tankDrive(leftWheelSpeed, rightWheelSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool Diagnostic::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Diagnostic::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Diagnostic::Interrupted() {

}

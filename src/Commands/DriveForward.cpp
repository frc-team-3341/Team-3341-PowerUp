#include "DriveForward.h"
#include "iostream"
using namespace std;

DriveForward::DriveForward(double _setpoint) : setpoint(_setpoint), pid(new WVPIDController(kP, kI, kD, setpoint, false)) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drive);
}

// Called just before this Command runs the first time
void DriveForward::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveForward::Execute() {
	double average = (drive->leftDistance() + drive->rightDistance()) / 2;
	drive->arcadeDrive(pid->Tick(average), 0);
	std::cout << "Value: " << std::endl;
}

// Make this return true when this Command no longer needs to run execute()
bool DriveForward::IsFinished() {
	return fabs(average - setpoint) < 0.05;
}

// Called once after isFinished returns true
void DriveForward::End() {
	drive->arcadeDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForward::Interrupted() {

}

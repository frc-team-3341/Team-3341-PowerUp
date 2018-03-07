#include "ArmPositionPID.h"

ArmPositionPID::ArmPositionPID() :
armPositionPid(new WVPIDController(0.05,0,0,0,false)),
absolutePosition(0),
speed(0)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(arm);
	//arm->getArmMotor()->ConfigSelectedFeedbackSensor(FeedbackDevice::Analog,0,10);
}

// Called just before this Command runs the first time
void ArmPositionPID::Initialize() {
	absolutePosition = arm->getPosition();
		std::cout << "absolutePosition: " << absolutePosition << std::endl;
		armPositionPid->SetSetPoint(absolutePosition);
}

// Called repeatedly when this Command is scheduled to run
void ArmPositionPID::Execute() {
	double currentPosition = arm->getPosition();
	speed = armPositionPid->Tick(currentPosition);
	std::cout << "speed: " << speed << "error value: " << armPositionPid->GetError() << std::endl;
	arm->move(arm->Limit(-speed,0.5));

	//double targetSpeed = oi->getArmStick()->GetY();
	//double adjSpeed = speedPID->Tick(targetSpeed);
	//arm->move(targetSpeed);

}

// Make this return true when this Command no longer needs to run execute()
bool ArmPositionPID::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ArmPositionPID::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmPositionPID::Interrupted() {

}

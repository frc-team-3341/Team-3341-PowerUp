#include "LiftPositionControl.h"

LiftPositionControl::LiftPositionControl() :
liftPositionPid(new WVPIDController(0.01,0,0,0,false)),
absolutePosition(0),
speed(0)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(lift);
	lift->getMotor()->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Absolute,0,10);
}

// Called just before this Command runs the first time
void LiftPositionControl::Initialize() {
	//lift->RobotSetClosedPositionLoop(lift->getMotor());
	absolutePosition = lift->getPosition();
	cout << "absolutePosition: " << absolutePosition << endl;
	liftPositionPid->SetSetPoint(absolutePosition);
}

// Called repeatedly when this Command is scheduled to run
void LiftPositionControl::Execute() {
	double currentPosition = lift->getPosition();
	speed = liftPositionPid->Tick(currentPosition);
	cout << "speed: " << speed << "error value: " << liftPositionPid->GetError() << endl;
	lift->move(lift->Limit(-speed,0.5));
}

// Make this return true when this Command no longer needs to run execute()
bool LiftPositionControl::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void LiftPositionControl::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftPositionControl::Interrupted() {

}

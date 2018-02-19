#include "ArmMin.h"

ArmMin::ArmMin() : anglePID(new WVPIDController(1, 0, 0, arm->getMin(), false)) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(arm);
}

// Called just before this Command runs the first time
void ArmMin::Initialize() {
	//arm->seta(true);
}

// Called repeatedly when this Command is scheduled to run
void ArmMin::Execute() {
	double measuredPower = anglePID->Tick(arm->getPosition());
	arm->move(measuredPower);
}

// Make this return true when this Command no longer needs to run execute()
bool ArmMin::IsFinished() {
	return anglePID->GetError() < 3; //can change as needed
}

// Called once after isFinished returns true
void ArmMin::End() {
	arm->move(0);
	//arm->seta(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmMin::Interrupted() {

}

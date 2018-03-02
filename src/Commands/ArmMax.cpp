#include "ArmMax.h"

ArmMax::ArmMax() : anglePID(new WVPIDController(0.01, 0, 0, arm->getMax(), false)) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(arm);
}

// Called just before this Command runs the first time
void ArmMax::Initialize() {
	//arm->seta(true);
}

// Called repeatedly when this Command is scheduled to run
void ArmMax::Execute() {
	double measuredPower = anglePID->Tick(arm->getPosition());
	arm->move(measuredPower);
}

// Make this return true when this Command no longer needs to run execute()
bool ArmMax::IsFinished() {
	return anglePID->GetError() < 2;
}

// Called once after isFinished returns true
void ArmMax::End() {
	arm->move(0);
	//arm->seta(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmMax::Interrupted() {

}

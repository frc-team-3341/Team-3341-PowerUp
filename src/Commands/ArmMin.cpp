#include "ArmMin.h"

ArmMin::ArmMin() //: anglePID(new WVPIDController(1, 0, 0, arm->getMin(), false))
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(arm);
}

// Called just before this Command runs the first time
void ArmMin::Initialize() {
	//arm->meta(true);
	arm->InitializeCounter();
	//i = 0;
}

// Called repeatedly when this Command is scheduled to run
void ArmMin::Execute() {
	//double measuredPower = anglePID->Tick(arm->getPosition());
	arm->move(.3);
	//i++;
	//temp = arm->getPosition();

	//Wait(2);

}

// Make this return true when this Command no longer needs to run execute()
bool ArmMin::IsFinished() {

	if(arm->getArmMotor()->GetSensorCollection().IsFwdLimitSwitchClosed() ||  arm->getPosition()<30)
	{
		return true;
	}
	else
		return false;


}

// Called once after isFinished returns true
void ArmMin::End() {
	//arm->move(0);
	//arm->seta(false);
	arm->reset();
	std::cout << "help" << std::endl;


}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmMin::Interrupted() {

}

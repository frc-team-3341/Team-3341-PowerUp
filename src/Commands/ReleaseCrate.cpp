#include "ReleaseCrate.h"
#include "CommandBase.h"

ReleaseCrate::ReleaseCrate()
{
	Requires(catcher);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void ReleaseCrate::Initialize()
{
	catcher->Enable();
}

// Called repeatedly when this Command is scheduled to run
void ReleaseCrate::Execute()
{
	catcher->CrateOut();
}

// Make this return true when this Command no longer needs to run execute()
bool ReleaseCrate::IsFinished()
{
	return !catcher->IsEnabled();
}

// Called once after isFinished returns true
void ReleaseCrate::End()
{
	catcher->Stop();
	catcher->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ReleaseCrate::Interrupted() {

}

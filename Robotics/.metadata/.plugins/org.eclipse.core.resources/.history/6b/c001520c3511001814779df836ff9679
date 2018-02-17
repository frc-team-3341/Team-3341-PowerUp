#include "AcquireCrate.h"
#include "CommandBase.h"

AcquireCrate::AcquireCrate()
{
	Requires(catcher);
}

// Called just before this Command runs the first time
void AcquireCrate::Initialize()
{
	catcher->Enable();
}

// Called repeatedly when this Command is scheduled to run
void AcquireCrate::Execute()
{
	catcher->CrateIn();
}

// Make this return true when this Command no longer needs to run execute()
bool AcquireCrate::IsFinished()
{
	return !catcher -> IsEnabled();
}

// Called once after isFinished returns true
void AcquireCrate::End()
{
	catcher->Stop();
	catcher->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AcquireCrate::Interrupted()
{

}

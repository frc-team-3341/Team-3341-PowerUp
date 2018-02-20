#include "StopCatcher.h"
#include "CommandBase.h"

StopCatcher::StopCatcher()
{
	Requires(catcher);
}

// Called just before this Command runs the first time
void StopCatcher::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void StopCatcher::Execute()
{
	catcher->Stop();
}

// Make this return true when this Command no longer needs to run execute()
bool StopCatcher::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void StopCatcher::End()
{
	catcher->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StopCatcher::Interrupted() {

}

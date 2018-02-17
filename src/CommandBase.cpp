#include "CommandBase.h"

#include <Commands/Scheduler.h>



// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.


std::unique_ptr<OI> CommandBase::oi;
DriveTrain* CommandBase::drive = nullptr;
Catcher* CommandBase::catcher = nullptr;


CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}

void CommandBase::initialize()
{
	oi = std::make_unique<OI>();
	drive = new DriveTrain();
	catcher = new Catcher();
}

#include "CommandBase.h"

#include <Commands/Scheduler.h>
#include "Subsystems/Drivetrain.h"
#include "Subsystems/ExampleSubsystem.h"

// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.
std::unique_ptr<ExampleSubsystem> CommandBase::exampleSubsystem =
		std::make_unique<ExampleSubsystem>();

std::unique_ptr<OI> CommandBase::oi;
Drivetrain * CommandBase::drive = nullptr;

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}

void CommandBase::initialize()
{
	drive = new Drivetrain();
	oi = std::make_unique<OI>();

}


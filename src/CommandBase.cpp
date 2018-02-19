#include "CommandBase.h"

#include <Commands/Scheduler.h>



// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.


OI* CommandBase::oi = nullptr;
DriveTrain* CommandBase::drive = nullptr;
Arm* CommandBase::arm = nullptr;

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}

void CommandBase::initialize() {

	//oi = std::make_unique<OI>();
	oi = new OI();
	drive = new DriveTrain();
	std::cout << "help me" << std::endl;
	arm = new Arm();

}

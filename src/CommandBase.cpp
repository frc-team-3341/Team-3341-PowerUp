#include "CommandBase.h"
#include <iostream>

#include <Commands/Scheduler.h>



// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.



DriveTrain* CommandBase::drive = nullptr;
Catcher* CommandBase::catcher = nullptr;
Lift* CommandBase::lift = nullptr;
std::unique_ptr<OI> CommandBase::oi;



CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}



void CommandBase::initialize()
{

	drive = new DriveTrain();
	std::cout << "drivetrain constructor completed" << std::endl;
	catcher = new Catcher();
	std::cout << "catcher constructor completed" << std::endl;
	lift = new Lift();
	std::cout << "lift constructor completed" << std::endl;
	oi = std::make_unique<OI>();
	std::cout << "commandBase initialize completed" << std::endl;


}

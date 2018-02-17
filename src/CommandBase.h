#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <memory>
#include <string>

#include <Commands/Command.h>

#include "Subsystems/Catcher.h"
#include "OI.h"
#include "Subsystems/DriveTrain.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use
 * CommandBase::exampleSubsystem
 */
class CommandBase: public frc::Command {
public:
	CommandBase(const std::string& name);
	CommandBase() = default;
	static void initialize();

	// Create a single static instance of all of your subsystems
	static std::unique_ptr<OI> oi;
	static DriveTrain* drive;
	static Catcher* catcher;
};

#endif  // COMMAND_BASE_H

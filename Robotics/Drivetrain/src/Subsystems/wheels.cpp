#include "wheels.h"
#include "../RobotMap.h"
#include "Phoenix.h"


wheels::wheels() : Subsystem("wheels")
:right(new Talon(13)), left(new Talon(14))
{

}

void wheels::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

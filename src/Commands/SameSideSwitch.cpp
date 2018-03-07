#include "SameSideSwitch.h"
#include "Commands/DriveForward.h"
#include "Commands/Turn.h"
SameSideSwitch::SameSideSwitch() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	AddSequential(new DriveForward(149)); //Travels 164 inches
	AddSequential(new Turn(90.0)); // Turns 90 deg
	AddSequential(new DriveForward(19.56)); // Travels 42 inches

	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}

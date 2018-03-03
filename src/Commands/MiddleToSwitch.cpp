#include "MiddleToSwitch.h"
#include "Commands/Turn.h"
#include "Commands/DriveForward.h"

MiddleToSwitch::MiddleToSwitch(char Pos) {

	if (Pos == 'L'){
		AddSequential(new DriveForward(55));
		AddSequential(new Turn(-90));
		AddSequential(new DriveForward(59));
		AddSequential(new Turn(90));
		AddSequential(new DriveForward(66));
	}

	else if (Pos == 'R') {
		AddSequential(new DriveForward(55));
		AddSequential(new Turn(90));
		AddSequential(new DriveForward(49));
		AddSequential(new Turn(-90));
		AddSequential(new DriveForward(66));
	}
	// Add Commands here:
	// e.g. AddSequential(new Command1());

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

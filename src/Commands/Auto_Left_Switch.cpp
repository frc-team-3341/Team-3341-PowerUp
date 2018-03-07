#include <Commands/Auto_Left_Switch.h>
#include <iostream>
#include "Delay.h"
#include "../CommandBase.h"
#include "Test_Mechs.h"
#include "ArmMin.h"
#include "MoveLiftToMinHeight.h"
#include "ArmPositionPID.h"

#include "ReleaseCrate.h"//#include "Constants.h"

Auto_Left_Switch::Auto_Left_Switch() {

	AddParallel(new ArmMin());
	AddSequential(new MoveLiftToMinHeight());
	AddSequential(new Delay(.5));
	AddSequential(new DriveForward(To_Switch-25));
	AddSequential(new Delay(.5));
	AddSequential(new Turn(85));
	AddParallel(new Test_Mechs());
	AddSequential(new Delay(.5));
	AddSequential(new DriveForward(Forward_Switch));
	AddParallel(new ReleaseCrate());
	AddSequential(new ArmPositionPID());




}

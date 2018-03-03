#include "Auto_Mid_LSwitch.h"
#include "../CommandBase.h"
#include "Delay.h"
#include "MoveLiftToMinHeight.h"
#include "MoveLiftToHeight.h"
#include "ArmPositionPID.h"
#include "AutoArmMove.h"
#include "ArmMin.h"
#include <iostream>
//#include "Constants.h"


Auto_Mid_LSwitch::Auto_Mid_LSwitch() {
	AddSequential(new ArmMin());
	AddSequential(new MoveLiftToMinHeight());
	AddSequential(new Delay(.5));
	AddSequential(new DriveForward(Forward_Mid));
	AddSequential(new Delay(.5));
	AddSequential(new Turn(-90));
	AddSequential(new Delay(.5));
	AddSequential(new DriveForward(Cross_MidL));
	AddSequential(new Delay(.5));
	AddSequential(new Turn(90));
	AddSequential(new Delay(.5));
	AddSequential(new DriveForward(Score_Mid));

	AddParallel(new MoveLiftToHeight(18));
	AddParallel(new AutoArmMove(100));
		//AddSequential(new MoveLiftToHeight(10));
		//AddSequential(new AutoArmMove(250));

	AddSequential(new ArmPositionPID());
	//AddSequential(new Arm(90,.5));
	//AddSequential(new Conveyor(45,2));
}

#include "Auto_Mid_LSwitch.h"
#include "../CommandBase.h"
#include "Delay.h"
#include "MoveLiftToMinHeight.h"
#include "MoveLiftToHeight.h"
#include "ArmPositionPID.h"
#include "AutoArmMove.h"
#include "ReleaseCrate.h"
#include "ArmMin.h"
#include "Test_Mechs.h"
#include <iostream>
//#include "Constants.h"


Auto_Mid_LSwitch::Auto_Mid_LSwitch() {
	AddParallel(new ArmMin());
	AddSequential(new MoveLiftToMinHeight());
	AddSequential(new Delay(.5));
	AddSequential(new DriveForward(Forward_Mid));
	AddSequential(new Delay(.5));
	AddSequential(new Turn(-90));
	AddSequential(new Delay(.5));
	AddSequential(new DriveForward(Cross_MidR-10));
	AddSequential(new Delay(.5));
	AddSequential(new Turn(90));
	AddParallel(new Test_Mechs());
	AddSequential(new Delay(.5));
	AddSequential(new DriveForward(Score_Mid));
	AddParallel(new ReleaseCrate());
	AddSequential(new ArmPositionPID());



}

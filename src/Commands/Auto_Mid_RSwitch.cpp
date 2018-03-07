#include "Auto_Mid_RSwitch.h"
#include "../CommandBase.h"
#include "Delay.h"
#include "MoveLiftToHeight.h"
#include "AutoArmMove.h"
#include "ReleaseCrate.h"
#include "ArmMin.h"
#include "MoveLiftToMinHeight.h"
#include "Test_Mechs.h"
#include "ArmPositionPID.h"
//#include "Constants.h"

Auto_Mid_RSwitch::Auto_Mid_RSwitch() {

	AddParallel(new ArmMin());
	AddSequential(new MoveLiftToMinHeight());
	AddSequential(new Delay(.5));
	AddSequential(new DriveForward(Forward_Mid-15));
	AddSequential(new Delay(.5));
	AddSequential(new Turn(90));
	AddSequential(new Delay(.5));
	AddSequential(new DriveForward(Cross_MidL-10));
	AddSequential(new Delay(.5));
	AddSequential(new Turn(-90));
	AddParallel(new Test_Mechs());
	AddSequential(new Delay(.5));
	AddSequential(new DriveForward(Score_Mid));
	AddParallel(new ReleaseCrate());
	AddSequential(new ArmPositionPID());

}

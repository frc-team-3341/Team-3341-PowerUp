#include "Auto_Right_Switch.h"
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

Auto_Right_Switch::Auto_Right_Switch() {

	AddParallel(new ArmMin());
	AddSequential(new MoveLiftToMinHeight());
	AddSequential(new Delay(.5));
	AddSequential(new DriveForward(To_Switch-25));
	AddSequential(new Delay(.5));
	AddSequential(new Turn(-85));
	AddSequential(new Delay(.5));
	AddParallel(new Test_Mechs());
	AddSequential(new Delay(.5));
	AddSequential(new DriveForward(Forward_Switch));
	AddParallel(new ReleaseCrate());
	AddSequential(new ArmPositionPID());




}

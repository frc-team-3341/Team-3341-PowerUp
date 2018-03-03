#include "Auto_Right_Switch.h"
#include "../CommandBase.h"
#include "Delay.h"

//#include "Constants.h"

Auto_Right_Switch::Auto_Right_Switch() {
	AddSequential(new DriveForward(To_Switch));
	AddSequential(new Delay(.5));
	AddSequential(new Turn(-85));
	AddSequential(new Delay(.5));
	AddSequential(new DriveForward(Forward_Switch));
	//AddSequential(new Arm(90,.5));
	//AddSequential(new Conveyor(45,2));
}

#include "Auto_Right_RScale.h"
#include "../CommandBase.h"
//#include "Constants.h"

Auto_Right_RScale::Auto_Right_RScale() {
	AddSequential(new DriveForward(To_Switch+Mid_Targets+To_Scale));
	AddSequential(new Turn(-90));
	AddSequential(new DriveForward(Forward_Scale));
	//AddSequential(new Arm(90));
//	AddSequential(new Conveyor(45,2));
}

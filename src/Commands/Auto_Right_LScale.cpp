#include <Commands/Auto_Right_LScale.h>
#include "../CommandBase.h"
#include "RobotMap.h"

Auto_Right_LScale::Auto_Right_LScale() {
	AddSequential(new DriveForward(To_Switch+Mid_Targets));
	AddSequential(new Turn(-90));
	AddSequential(new DriveForward(Cross_Field));
	AddSequential(new Turn(90));
	AddSequential(new DriveForward(To_Scale));
	AddSequential(new Turn(90));
	AddSequential(new DriveForward(Forward_Scale));
	//AddSequential(new Arm(180,.5));
	//AddSequential(new Conveyor(45,2));
}

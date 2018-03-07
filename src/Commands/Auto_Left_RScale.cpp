#include <Commands/Auto_Left_RScale.h>
#include "../CommandBase.h"
#include "ScaleMechanisms.h"
#include "RobotMap.h"

Auto_Left_RScale::Auto_Left_RScale() {
	AddSequential(new DriveForward(To_Switch+Mid_Targets));
	AddSequential(new Turn(90));
	AddSequential(new DriveForward(Cross_Field));
	AddSequential(new Turn(-90));
	AddSequential(new DriveForward(To_Scale));
	AddSequential(new Turn(-90));
	AddSequential(new DriveForward(Forward_Scale));
	AddParallel(new ScaleMechanisms());
	//AddSequential(new Arm(180,.5));
	//AddSequential(new Conveyor(45,2));
}

#include "Auto_Mid_RSwitch.h"
#include "../CommandBase.h"
//#include "Constants.h"

Auto_Mid_RSwitch::Auto_Mid_RSwitch() {
	AddSequential(new DriveForward(Forward_Mid));
	AddSequential(new Turn(90));
	AddSequential(new DriveForward(Cross_MidR));
	AddSequential(new Turn(-90));
	AddSequential(new DriveForward(Score_Mid));
	//AddSequential(new Arm(90,.5));
	//AddSequential(new Conveyor(45,2));
}

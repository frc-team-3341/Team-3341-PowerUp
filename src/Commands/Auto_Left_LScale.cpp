#include "Auto_Left_LScale.h"
#include "../CommandBase.h"
using namespace std;

Auto_Left_LScale::Auto_Left_LScale() {
	//cout << "Auto Left L scale" << endl;
	AddSequential(new DriveForward(To_Switch+Mid_Targets+To_Scale));
	AddSequential(new Turn(90));
	AddSequential(new DriveForward(Forward_Scale));
	//AddSequential(new Arm(90,.5));
	//AddSequential(new Conveyor(45,2));
}

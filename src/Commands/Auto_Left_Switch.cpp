#include <Commands/Auto_Left_Switch.h>
#include <iostream>
#include "Delay.h"
#include "../CommandBase.h"
//#include "Constants.h"

Auto_Left_Switch::Auto_Left_Switch() {
	AddSequential(new DriveForward(To_Switch));
	std::cout<<"PLEASE"<<std::endl;
	AddSequential(new Delay(5));
	AddSequential(new Turn(90));
	std::cout<<"NEXT_PLEASE"<<std::endl;
	AddSequential(new Delay(5));
	AddSequential(new DriveForward(Forward_Switch));
	//AddSequential(new Arm(90,.5));
	//AddSequential(new Conveyor(45,2));
}

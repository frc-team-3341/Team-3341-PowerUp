/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RightSwitch.h"
#include "Auto_Right_RScale.h"
#include "Auto_Right_LScale.h"
#include "Auto_Right_Switch.h"

RightSwitch::RightSwitch(std::string s) {
	if(s[0] == 'L'){
			if(s[1] == 'L')
				AddSequential(new Auto_Right_LScale());
			else
				AddSequential(new Auto_Right_RScale());
		}
		else {
			AddSequential(new Auto_Right_Switch());
		}
}

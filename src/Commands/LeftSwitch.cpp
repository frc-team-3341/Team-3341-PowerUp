/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "LeftSwitch.h"
#include "Auto_Left_RScale.h"
#include "Auto_Left_LScale.h"
#include "Auto_Left_Switch.h"

LeftSwitch::LeftSwitch(std::string s) {
	if(s[0] == 'R'){
		if(s[1] == 'R')
			AddSequential(new Auto_Left_RScale());
		else
			AddSequential(new Auto_Left_LScale());
	}
	else {
		AddSequential(new Auto_Left_Switch());
	}
}

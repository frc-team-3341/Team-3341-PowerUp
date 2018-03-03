/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Commands/LSwitchScale.h>
#include "Auto_Left_RScale.h"
#include "Auto_Left_LScale.h"
#include "Auto_Left_Switch.h"

LSwitchScale::LSwitchScale(std::string s) {
		if(s[0] == 'L')
			AddSequential(new Auto_Left_Switch());
		else if(s[1] == 'L'){
			AddSequential(new Auto_Left_LScale());
		}
		else
			AddSequential(new DriveForward(To_Switch+Mid_Targets));

}

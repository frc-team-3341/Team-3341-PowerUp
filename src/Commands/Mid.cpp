/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Mid.h"
#include "Auto_Mid_LSwitch.h"
#include "Auto_Mid_RSwitch.h"
#include <iostream>

Mid::Mid(std::string s) {
	if(s[0] == 'L')
		AddSequential(new Auto_Mid_LSwitch());
	else
		AddSequential(new Auto_Mid_RSwitch());
}

/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "TurnTest.h"
#include "Turn2.h"
#include "Delay.h"
#include <iostream>

TurnTest::TurnTest() {
	for(double i = .03; i<=1; i+=.01){
		AddSequential(new Turn2(90,i));
		AddSequential(new Delay(3));
		std::cout<<i<<std::endl;
	}
}

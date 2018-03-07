/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Command.h>
#include "../CommandBase.h"
#include "../Utilities/WVPIDController.h"

class AutoArmMove : public CommandBase {

private:
	WVPIDController* anglePID;
	int iterator;
	double lastval;
	double measuredVal;

public:
	AutoArmMove(double target);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};


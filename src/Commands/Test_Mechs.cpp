/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Test_Mechs.h"
#include "MoveLiftToMinHeight.h"
#include "MoveLiftToHeight.h"
#include "ArmPositionPID.h"
#include "AutoArmMove.h"
#include "ReleaseCrate.h"
#include "ArmMin.h"
#include "ResetLiftEnc.h"
#include <Commands/CommandGroup.h>

Test_Mechs::Test_Mechs() {


	AddSequential(new ArmMin());
	AddSequential(new MoveLiftToMinHeight());
	AddSequential(new ResetLiftEnc(0.1));
	AddSequential(new AutoArmMove(250));

	AddParallel(new ArmPositionPID());


}

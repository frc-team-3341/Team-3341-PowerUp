/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "MoveLiftToMinHeight.h"
#include "MoveLiftToHeight.h"
#include "ArmPositionPID.h"
#include "AutoArmMove.h"
#include "ReleaseCrate.h"
#include "ArmMin.h"
#include <Commands/CommandGroup.h>
#include <Commands/ScaleMechanisms.h>
#include "ResetLiftEnc.h"

ScaleMechanisms::ScaleMechanisms() {

	AddParallel(new ArmMin());
	AddSequential(new MoveLiftToMinHeight());
	AddSequential(new ResetLiftEnc(0.1));

	AddParallel(new MoveLiftToHeight(21));
	AddSequential(new AutoArmMove(360));

	AddSequential(new ArmPositionPID());
}

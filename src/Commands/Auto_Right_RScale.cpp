#include "Auto_Right_RScale.h"
#include "../CommandBase.h"
#include "Delay.h"
#include "ArmMin.h"
#include "MoveLiftToMinHeight.h"
#include "ReleaseCrate.h"
#include "ScaleMechanisms.h"
#include "ArmPositionPID.h"
//#include "Constants.h"

Auto_Right_RScale::Auto_Right_RScale() {

	AddParallel(new ArmMin());
	AddSequential(new MoveLiftToMinHeight());
	AddSequential(new Delay(.5));
	AddParallel(new ScaleMechanisms());
	AddSequential(new DriveForward(To_Switch+Mid_Targets+To_Scale-35));
	AddSequential(new Delay(.5));
	AddSequential(new Turn(-90));
	AddSequential(new Delay(.5));
	AddSequential(new DriveForward(Forward_Scale+15));
	AddSequential(new Delay(.5));
	AddParallel(new ReleaseCrate());
	AddSequential(new ArmPositionPID());
}

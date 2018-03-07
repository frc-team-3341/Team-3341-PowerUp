#include "Auto_Left_LScale.h"
#include "../CommandBase.h"
#include "Delay.h"
#include "MoveLiftToHeight.h"
#include "AutoArmMove.h"
#include "ReleaseCrate.h"
#include "ArmMin.h"
#include "MoveLiftToMinHeight.h"
#include "Test_Mechs.h"
#include "ScaleMechanisms.h"
#include "ArmPositionPID.h"
using namespace std;

Auto_Left_LScale::Auto_Left_LScale() {
	//cout << "Auto Left L scale" << endl;
	AddParallel(new ArmMin());
	AddSequential(new MoveLiftToMinHeight());
	AddSequential(new Delay(.5));
	AddParallel(new ScaleMechanisms());
	AddSequential(new DriveForward(To_Switch+Mid_Targets+To_Scale-35));
	AddSequential(new Delay(.5));
	AddSequential(new Turn(90));
	AddSequential(new Delay(.5));
	AddSequential(new DriveForward(Forward_Scale+15));
	AddSequential(new Delay(.5));
	AddParallel(new ReleaseCrate());
	AddSequential(new ArmPositionPID());




}

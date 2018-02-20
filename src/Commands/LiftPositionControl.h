#ifndef LiftPositionControl_H
#define LiftPositionControl_H

#include "../CommandBase.h"
#include "Utilities/WVPIDController.h"
#include <iostream>
#include <WPILib.h>
using namespace std;

class LiftPositionControl : public CommandBase {
private:
	WVPIDController* liftPositionPid;
	double relativePosition;
	double speed;

public:
	LiftPositionControl();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LiftPositionControl_H

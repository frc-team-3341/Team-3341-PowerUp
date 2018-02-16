#ifndef LiftPositionControl_H
#define LiftPositionControl_H

#include "../CommandBase.h"
#include "Utilities/WVPIDController.h"
#include <iostream>
using namespace std;

class LiftPositionControl : public CommandBase {
private:
	WVPIDController* liftPositionPid;
	double absolutePosition;
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

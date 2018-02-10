#ifndef LiftPositionControl_H
#define LiftPositionControl_H

#include "../CommandBase.h"

class LiftPositionControl : public CommandBase {
public:
	LiftPositionControl();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // LiftPositionControl_H

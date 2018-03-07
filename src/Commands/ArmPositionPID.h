#ifndef ArmPositionPID_H
#define ArmPositionPID_H

#include "../CommandBase.h"
#include "../Utilities/WVPIDController.h"

class ArmPositionPID : public CommandBase {
private:
	WVPIDController* armPositionPid;
	double absolutePosition;
	double speed;

public:
	ArmPositionPID();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ArmPositionPID_H

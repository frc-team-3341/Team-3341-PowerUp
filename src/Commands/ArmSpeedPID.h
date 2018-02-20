#ifndef ArmSpeedPID_H
#define ArmSpeedPID_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../Utilities/WVPIDController.h"

class ArmSpeedPID : public CommandBase {

private:
	//WVPIDController* speedPID;

public:
	ArmSpeedPID();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ArmSpeedPID_H

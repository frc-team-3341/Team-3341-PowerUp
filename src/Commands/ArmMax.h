#ifndef ArmMax_H
#define ArmMax_H

#include "../CommandBase.h"
#include "../Utilities/WVPIDController.h"

class ArmMax : public CommandBase {

private:
	WVPIDController* anglePID;
public:
	ArmMax();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ArmMax_H

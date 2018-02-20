#ifndef ArmMin_H
#define ArmMin_H

#include "../CommandBase.h"
#include "../Utilities/WVPIDController.h"

class ArmMin : public CommandBase {

private:
	//WVPIDController* anglePID;
	double temp;

public:
	ArmMin();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ArmMin_H

#ifndef MoveLiftToHeight_H
#define MoveLiftToHeight_H

#include "../CommandBase.h"
#include "../Utilities/WVPIDController.h"
#include <iostream>

using namespace std;

class MoveLiftToHeight : public CommandBase {
private:
	double targetHeight;
	WVPIDController* heightPid;
	int timeCount;

public:
	MoveLiftToHeight(double height);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveLiftToHeight_H

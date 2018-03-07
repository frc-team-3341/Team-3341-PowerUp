#ifndef MoveLiftToHeight_H
#define MoveLiftToHeight_H

#include "../CommandBase.h"
#include "../Utilities/WVPIDController.h"

class MoveLiftToHeight : public CommandBase {
private:
	double targetHeight;
	WVPIDController* heightPid;
	int iterator;
	double lastval;
	double height;

public:
	MoveLiftToHeight(double height);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveLiftToHeight_H

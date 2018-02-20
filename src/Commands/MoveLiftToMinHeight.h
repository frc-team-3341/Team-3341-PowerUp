#ifndef MoveLiftToMinHeight_H
#define MoveLiftToMinHeight_H

#include "..\CommandBase.h"
#include "RobotMap.h"
#include "Math.h"

class MoveLiftToMinHeight : public CommandBase {
private:

public:
	MoveLiftToMinHeight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveLiftToMinHeight_H

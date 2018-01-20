#ifndef MoveLiftToMaxHeight_H
#define MoveLiftToMaxHeight_H

#include "../CommandBase.h"
#include "../Subsystems/Lift.h"

class MoveLiftToMaxHeight : public CommandBase {
public:
	MoveLiftToMaxHeight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveLiftToMaxHeight_H

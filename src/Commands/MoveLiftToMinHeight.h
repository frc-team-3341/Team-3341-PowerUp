#ifndef MoveLiftToMinHeight_H
#define MoveLiftToMinHeight_H

#include "../CommandBase.h"

class MoveLiftToMinHeight : public CommandBase {
public:
	MoveLiftToMinHeight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveLiftToMinHeight_H

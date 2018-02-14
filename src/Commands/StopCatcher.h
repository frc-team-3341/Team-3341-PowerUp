#ifndef StopCatcher_H
#define StopCatcher_H

#include "../CommandBase.h"
#include "WPILib.h"

class StopCatcher : public CommandBase {
public:
	StopCatcher();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // StopCatcher_H

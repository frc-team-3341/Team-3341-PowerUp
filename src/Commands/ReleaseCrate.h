#ifndef ReleaseCrate_H
#define ReleaseCrate_H

#include "../CommandBase.h"
#include "WPILib.h"

class ReleaseCrate : public CommandBase {
public:
	ReleaseCrate();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ReleaseCrate_H

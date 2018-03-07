#ifndef AcquireCrate_H
#define AcquireCrate_H

#include "../CommandBase.h"
#include "WPILib.h"

class AcquireCrate : public CommandBase {
public:
	AcquireCrate();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AcquireCrate_H

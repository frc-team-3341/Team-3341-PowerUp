#ifndef Diagnostic_H
#define Diagnostic_H

#include <WPILib.h>
#include "../CommandBase.h"

class Diagnostic : public CommandBase {
public:
	Diagnostic();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Diagnostic_H

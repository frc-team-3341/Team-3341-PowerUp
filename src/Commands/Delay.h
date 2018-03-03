#ifndef Delay_H

#define Delay_H



#include "CommandBase.h"

#include "WPILib.h"

#include "Timer.h"


//#include ""



class Delay: public CommandBase {

public:

	Delay(double timeout);

	void Initialize();

	void Execute();bool IsFinished();

	void End();

	void Interrupted();

private:

	double timer;

};



#endif

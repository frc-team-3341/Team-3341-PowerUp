#ifndef Delay_H

#define Delay_H



#include "CommandBase.h"

#include "WPILib.h"



//#include ""



class Delay: public CommandBase {

public:

	Delay(float timeout);

	void Initialize();

	void Execute();bool IsFinished();

	void End();

	void Interrupted();

private:

	float timer;

};



#endif

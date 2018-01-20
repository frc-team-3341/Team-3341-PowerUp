#ifndef MoveLift_H
#define MoveLift_H

#include "../CommandBase.h"

class MoveLift : public CommandBase {
private:
	double liftHeight;

public:
	MoveLift(double height);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MoveLift_H

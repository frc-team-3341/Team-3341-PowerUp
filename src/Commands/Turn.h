#ifndef Turn_H
#define Turn_H

#include "../CommandBase.h"
#include "Utilities/WVPIDController.h"

class Turn : public CommandBase {
private:
	double kP = 0.5;
	double kI = 0.0;
	double kD = 0.05;
	double setpoint;
	double angle = 0;
	WVPIDController* pid;
public:
	Turn(double _setpoint);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Turn_H

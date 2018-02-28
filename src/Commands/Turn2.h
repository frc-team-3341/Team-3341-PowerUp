#ifndef Turn2_H
#define Turn2_H

#include "../Utilities/AutoWVPIDController.h"
#include "../CommandBase.h"

class Turn2 : public CommandBase {
	public:
	Turn2(double _setpoint, double kP);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	//double kP = 0.05;
	double kI = 0;
	double kD = 0.0;
	double setpoint;
	double angle = 0;
	double speed = 0;
	AutoWVPIDController* pid;
};

#endif  // Turn_H

#ifndef DriveForward_H
#define DriveForward_H

#include "../CommandBase.h"
#include "Utilities/WVPIDController.h"

class DriveForward : public CommandBase {
private:
	double kP = 0.5;
	double kI = 0;
	double kD = 0;
	double setpoint;
	double average = 0;
	WVPIDController* pid;
public:
	DriveForward(double _setpoint);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveForward_H

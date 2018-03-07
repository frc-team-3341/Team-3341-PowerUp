#ifndef DriveForward_H
#define DriveForward_H

#include <Utilities/AutoWVPIDController.h>
#include "../CommandBase.h"

class DriveForward : public CommandBase {
private:
	double distKp = 0.005;
	double disKi = 0;
	double distKd = 0;
	double angleKp = 0.05;
	double angleKi = 0;
	double angleKd = 0;
	double setpoint;
	double average = 0;
	double angle = 0;
	int iterator = 0;
	double MULT = 1.2;
	bool isLeft = false;
	bool isRight = false;
	double startDistPidValue;
	double lastval = 1000.0;
	double bound;

	AutoWVPIDController* distancePid;
	AutoWVPIDController* anglePid;
public:
	DriveForward(double _setpoint);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void setAngle();
};

#endif  // DriveForward_H

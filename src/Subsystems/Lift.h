#ifndef Lift_H
#define Lift_H

#include <Commands/Subsystem.h>
#include "ctre/Phoenix.h"
#include "RobotMap.h"

#include <WPILib.h>
#include "Utilities/WVPIDController.h"

class Lift : public Subsystem {
private:
	TalonSRX* motor;
	double ticksPerDistance;
	double liftHeight;

public:
	Lift();
	~Lift();
	void InitDefaultCommand();
	void move(double speed);
	TalonSRX* getMotor();
	float Limit(float num, float max);
	void setHeight(double height);
	double getHeight();
	void resetEncoder();
	void RobotSetClosedPositionLoop(TalonSRX* talon);
	//WVPIDController* getHeightPid();
	//WVPIDController* getLiftPositionPid();
	double getPosition();
};

#endif  // Lift_H

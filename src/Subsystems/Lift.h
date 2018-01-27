#ifndef Lift_H
#define Lift_H

#include <Commands/Subsystem.h>
#include "ctrlib/CANTalon.h"
#include "RobotMap.h"
#include "../Commands/MoveLift.h"

class Lift : public Subsystem {
private:
	CANTalon* motor;
	double circumference;

public:
	Lift();
	~Lift();
	void InitDefaultCommand();
	void move(double speed);
	double getHeight();
	double getVelocity();
	CANTalon* getMotor();
	float Limit(float num, float max);
	double liftDistance();
};

#endif  // Lift_H

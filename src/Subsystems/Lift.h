#ifndef Lift_H
#define Lift_H

#include <Commands/Subsystem.h>
#include "ctrlib/CANTalon.h"
#include "RobotMap.h"

class Lift : public Subsystem {
private:
	CANTalon* motor;

public:
	Lift();
	~Lift();
	void InitDefaultCommand();
	void move(double power);
	double getHeight();
	double getVelocity();
};

#endif  // Lift_H

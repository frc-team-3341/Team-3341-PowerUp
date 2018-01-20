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
	void move(double speed);
	double getHeight();
	double getVelocity();
	CANTalon* getMotor();
};

#endif  // Lift_H

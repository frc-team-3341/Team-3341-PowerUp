#ifndef Drivetrain_H
#define Drivetrain_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "ctre/Phoenix.h"
class Drivetrain : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	TalonSRX * rightMotor;
	TalonSRX * leftMotor;
public:
	Drivetrain();
	void InitDefaultCommand();
	void StartDrive(double leftVal, double rightVal);
};

#endif  // Drivetrain_H

#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "ctre/Phoenix.h"
#include "RobotMap.h"

class DriveTrain : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	TalonSRX* right;
	TalonSRX* left;
	RobotDrive* drivetrain;
	double circumference = 6 * M_PI;

public:
	DriveTrain();
	void InitDefaultCommand();
	void tankDrive(Joystick* left, Joystick* right);
	void arcadeDrive(double moveVal, double rotateVal);
	double leftDistance();
	double rightDistance();
};

#endif  // DriveTrain_H

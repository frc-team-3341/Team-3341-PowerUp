#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "ctrlib/CANTalon.h"

class DriveTrain : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon* left;
	CANTalon* right;
	RobotDrive* drivetrain;
	Encoder* encoderLeft;
	Encoder* encoderRight;
public:
	DriveTrain();
	void InitDefaultCommand();
	void tankDrive(Joystick* left, Joystick* right);
	void arcadeDrive(double moveVal, double rotateVal);
};

#endif  // DriveTrain_H

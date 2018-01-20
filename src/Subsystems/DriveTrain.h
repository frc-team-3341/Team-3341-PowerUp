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
	ADXRS450_Gyro* gyro;
public:
	DriveTrain();
	void InitDefaultCommand();
	double Limit(double num, double max);
	void tankDrive(double leftVal, double rightVal);
	void arcadeDrive(double moveVal, double rotateVal);
	double getAngle();
	double leftDistance();
	double rightDistance();
};

#endif  // DriveTrain_H

#ifndef DriveTrain_H
#define DriveTrain_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "ctre/Phoenix.h"
#include "math.h"

class DriveTrain : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	TalonSRX* left;
	TalonSRX* right;
	ADXRS450_Gyro* gyro;
	double circumference = 6 * M_PI; //diameter = 6 inches

public:
	DriveTrain();
	void InitDefaultCommand();
	void tankDrive(double leftVal, double rightVal);
	void arcadeDrive(double moveVal, double rotateVal, double limit);
	double Limit(double num, double max);
	double getAngle();
	double getSpeed();
	void gyroReset();
	double leftDistance(); //inches
	double rightDistance(); //inches
	void resetEncoders();
	void gyroCalibrate();
	//double startAbsTicks;
	//void setStartAbsTicks();

};

#endif  // DriveTrain_H

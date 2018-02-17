#ifndef Drivetrain_H
#define Drivetrain_H

//#include "CANTalon.h"
#include "ctrlib/CANTalon.h"
#include <WPILib.h>
#include <Commands/Subsystem.h>

class Drivetrain : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon * rightMotor;
	CANTalon * leftMotor;


public:
	Drivetrain();
	~Drivetrain();
	double Limit(double num, double max);
	void InitDefaultCommand();
	void tankDrive(double leftVal, double rightVal);
	void reverseDir();
};

#endif  // Drivetrain_H

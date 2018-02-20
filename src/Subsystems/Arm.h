#ifndef Arm_H
#define Arm_H

#include <Commands/Subsystem.h>
#include "ctre/Phoenix.h"
#include <WPILib.h>


#include "math.h"

class Arm : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	TalonSRX* armMotor;
	//Encoder* armEncoder;
	double maxPosition;
	double minPosition;
	DigitalInput* lowLimit;
	Counter* counter;

public:
	Arm();
	void InitDefaultCommand();
	void move(double power);
	void reset();
	double getPosition();
	double getSpeed();
	double Limit(double num, double max);
	//Encoder* getEncoder();
	TalonSRX* getArmMotor();
	double getMin();
	double getMax();

	bool IsSwitchSet();
	void InitializeCounter();

	//double test();
	//bool whenyouarerunningabuttoncommanditistrue;
	//void seta(bool ean);
	//daniel's fault for these long variable names
	//"alittlebitlessthanmax" and "alittlebitmorethanmin"

};

#endif  // Arm_H

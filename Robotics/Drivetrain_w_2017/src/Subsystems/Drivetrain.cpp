#include "Drivetrain.h"
#include "../RobotMap.h"


Drivetrain::Drivetrain() : Subsystem("Drivetrain"),
rightMotor(new PWMTalonSRX(14)), leftMotor(new PWMTalonSRX(15))
{
	rightMotor->SetInverted(true);
	leftMotor->SetInverted(false);
}

void Drivetrain::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new TankDrive());
}

void Drivetrain::StartDrive(double leftVal, double rightVal)
{
	leftMotor->Set(ControlMode::Velocity, leftVal);
	leftMotor->set
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

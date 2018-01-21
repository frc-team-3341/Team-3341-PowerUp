#include "DriveTrain.h"
#include "../RobotMap.h"
#include "../Commands/TankDrive.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain"), left(new CANTalon(LEFTMOTOR)), right(new CANTalon(RIGHTMOTOR)),
drivetrain(new RobotDrive(left, right))
{

}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new TankDrive());
}

void DriveTrain::tankDrive(Joystick* left, Joystick* right)
{
	drivetrain->TankDrive(left, right);
}

void DriveTrain::arcadeDrive(double moveVal, double rotateVal)
{
	drivetrain->Drive(moveVal, rotateVal);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

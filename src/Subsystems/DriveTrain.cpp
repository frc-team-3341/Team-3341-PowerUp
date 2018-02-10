#include "DriveTrain.h"
#include "../RobotMap.h"
#include "../Commands/TankDrive.h"
#include "iostream"
using namespace std;

DriveTrain::DriveTrain() : Subsystem("DriveTrain"),
left(new TalonSRX(LEFTMOTOR)),
right(new TalonSRX(RIGHTMOTOR)),
drivetrain(new RobotDrive(LEFTMOTOR, RIGHTMOTOR))
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

double DriveTrain::leftDistance()
{
	double relativePosition = (left->GetSensorCollection().GetQuadraturePosition());
	relativePosition = (relativePosition / 4096) * circumference;
	std::cout << "Left Wheel Relative Position: " << relativePosition << std::endl;
}

double DriveTrain::rightDistance()
{
	double relativePosition = -(right->GetSensorCollection().GetQuadraturePosition());
	relativePosition = (relativePosition / 4096) * circumference;
	std::cout << "Right Wheel Relative Position: " << relativePosition << std::endl;
}

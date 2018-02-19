#include "Arm.h"
#include "../RobotMap.h"
#include "../Commands/ArmSpeedPID.h"

Arm::Arm() : Subsystem("ExampleSubsystem"), armMotor(new TalonSRX(ARMMOTOR)),
armEncoder(new frc::Encoder(0, 1)), minPosition(0)
{
	armEncoder->Reset();
}

void Arm::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new ArmSpeedPID());
}

void Arm::move(double power) {
	armMotor->Set(ControlMode::PercentOutput, Arm::Limit(power, 0.5));
}

void Arm::reset()
{
	armEncoder->Reset();
}

double Arm::getPosition() {
	return (double) armEncoder->Get();
}

double Arm::getSpeed() {
	return armEncoder->GetRate();
}

Encoder* Arm::getEncoder() {
	return armEncoder;
}

TalonSRX* Arm::getArmMotor() {
	return armMotor;
}

double Arm::Limit(double num, double max) {
	if (num > max)
		return max;

	if (num < -max)
		return -max;

	return num;
}

double Arm::getMin()
{
	return minPosition;
}

double Arm::getMax()
{
	return maxPosition;
}

//void Arm::seta(bool ean) {
	//whenyouarerunningabuttoncommanditistrue = ean;
//}

// Put methods for controlling this subsystem
// here. Call these from Commands.

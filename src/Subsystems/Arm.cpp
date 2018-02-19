#include "Arm.h"
#include "../RobotMap.h"
#include "../Commands/ArmSpeedPID.h"

Arm::Arm() : Subsystem("Arm"), armMotor(new TalonSRX(ARMMOTOR)), minPosition(0)
{
	//armEncoder->Reset();
	armMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::Analog, 0, 10);
		// left->ConfigEncoderCodesPerRev(360);
	armMotor->SetSelectedSensorPosition(0,0,10);
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
	armMotor->SetSelectedSensorPosition(0,0,10);
}

double Arm::getPosition() {
	return armMotor->GetSelectedSensorPosition(0);
}

double Arm::getSpeed() {
	return armMotor->GetSelectedSensorVelocity(0);
}

//Encoder* Arm::getEncoder() {
	//return armEncoder;
//}

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

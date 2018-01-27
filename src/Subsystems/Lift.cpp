#include "Lift.h"
#include "../RobotMap.h"

Lift::Lift() : Subsystem("Lift"),
motor(new CANTalon(LIFT_MOTOR)),
circumference(5)
{
	motor->SetFeedbackDevice(CANTalon::CtreMagEncoder_Absolute);
	motor->ConfigEncoderCodesPerRev(360);
	motor->SetPosition(0);
}

Lift::~Lift()
{
	delete motor;
}

void Lift::InitDefaultCommand() {
	SetDefaultCommand(new MoveLift());
}

void Lift::move(double speed)
{
	motor->Set(Lift::Limit(speed, 0.5));
	// TODO: may need mapping
}

double Lift::getHeight()
{
	return motor->GetEncPosition();
}

double Lift::getVelocity()
{
	return motor->GetEncVel();
}

CANTalon* Lift::getMotor()
{
	return motor;
}

float Lift::Limit(float num, float max) {
	if (num > max)
		return max;
	if (num < -max)
		return -max;

	return num;
}

double Lift::liftDistance() { //inches
	double absolutePosition = (double) (motor->GetPulseWidthPosition() & 0xFFF);
	absolutePosition = absolutePosition * circumference / 360;
	return absolutePosition;
}

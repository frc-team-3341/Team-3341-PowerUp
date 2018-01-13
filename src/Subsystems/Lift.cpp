#include "Lift.h"
#include "../RobotMap.h"

Lift::Lift() : Subsystem("Lift"), motor(new CANTalon(LIFT_MOTOR)) {

}

Lift::~Lift()
{
	delete motor;
}

void Lift::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Lift::move(double power)
{
	motor->Set(power);
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

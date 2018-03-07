#include "Catcher.h"
#include "../RobotMap.h"

Catcher::Catcher(): Subsystem("Catcher"),
catcherLeft(new TalonSRX(CATCH_LEFT_CAN_ID)), catcherRight(new TalonSRX(CATCH_RIGHT_CAN_ID))
{
	enabled = false;

}

Catcher::~Catcher()
{
	delete catcherLeft;
	delete catcherRight;
	catcherLeft = nullptr;
	catcherRight = nullptr;
}

void Catcher::InitDefaultCommand()
{

}

void Catcher::Enable()
{
	enabled = true;
}

void Catcher::Disable()
{
	enabled = false;
}

void Catcher::CrateIn()
{
	if (enabled)
		catcherLeft->Set(ControlMode::PercentOutput, -1);
		catcherRight->Set(ControlMode::PercentOutput, 1);
}

void Catcher::CrateOut()
{
    if(enabled)
    	catcherLeft->Set(ControlMode::PercentOutput, 0.4);
    	catcherRight->Set(ControlMode::PercentOutput, -0.4);
}

void Catcher::Stop()
{
	catcherLeft->Set(ControlMode::PercentOutput, 0);
	catcherRight->Set(ControlMode::PercentOutput, 0);
}

bool Catcher::IsEnabled()
{
    return enabled;
}


void Catcher::moveTogether(double speed, Direction catchDirection)
{
	enabled = true;
	if(catchDirection == in)
	{
		catcherLeft->Set(ControlMode::PercentOutput, speed);
		catcherRight->Set(ControlMode::PercentOutput, -speed);
	}
	if(catchDirection == out)
	{
		catcherLeft->Set(ControlMode::PercentOutput, -speed);
		catcherRight->Set(ControlMode::PercentOutput, speed);
	}
}

void Catcher::moveLeft(double speed, Direction catchDirection)
{
	if (catchDirection == in)
	{
		catcherLeft->Set(ControlMode::PercentOutput, speed);
	}
	else if (catchDirection == out)
	{
		catcherLeft->Set(ControlMode::PercentOutput, -speed);
	}
}

void Catcher::moveRight(double speed, Direction catchDirection)
{
	if (catchDirection == in)
	{
		catcherRight->Set(ControlMode::PercentOutput, -speed);
	}
	else if (catchDirection == out)
	{
		catcherRight->Set(ControlMode::PercentOutput, speed);
	}
}

double Catcher::getSpeedLeft()
{
	return catcherLeft->GetSensorCollection().GetQuadratureVelocity();
}

double Catcher::getSpeedright()
{
	return catcherRight->GetSensorCollection().GetQuadratureVelocity();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

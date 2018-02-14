#include "Catcher.h"
#include "../RobotMap.h"

Catcher::Catcher(): Subsystem("Catcher"),
left(new CANTalon(CATCH_LEFT_CAN_ID)),
right(new CANTalon(CATCH_RIGHT_CAN_ID))
{
	enabled = false;
}

Catcher::~Catcher()
{
	delete left;
	delete right;
	left = nullptr;
	right = nullptr;
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

void Catcher::CrateOut()
{
	if (enabled)
		left->Set(-1);
		right->Set(1);
}

void Catcher::CrateIn()
{
    if(enabled)
    	left->Set(1);
    	right->Set(-1);
}

void Catcher::Stop()
{
	left->Set(0);
	right->Set(0);
}

bool Catcher::IsEnabled()
{
    return enabled;
}


void Catcher::moveTogether(double speed, Direction catchDirection)
{
	enabled = true;
	if(catchDirection == in)
		left->Set(speed);
		right->Set(-speed);
	if(catchDirection == out)
		left->Set(-speed);
		right->Set(speed);
}

void Catcher::moveLeft(double speed, Direction catchDirection)
{
	if (catchDirection == in)
		left->Set(speed);
	else if (catchDirection == out)
		left->Set(-speed);
}

void Catcher::moveRight(double speed, Direction catchDirection)
{
	if (catchDirection == in)
		right->Set(-speed);
	else if (catchDirection == out)
		right->Set(speed);
}

double Catcher::getSpeedLeft()
{
	return left->GetEncVel();
}

double Catcher::getSpeedright()
{
	return right->GetEncVel();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

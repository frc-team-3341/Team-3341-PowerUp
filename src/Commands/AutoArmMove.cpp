/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "AutoArmMove.h"


AutoArmMove::AutoArmMove(double target) :
anglePID(new WVPIDController(0.02, 0, 0, target, false)) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::arm);
}

// Called just before this Command runs the first time
void AutoArmMove::Initialize()
{
	std::cout << "ARRRRRRRRRRRRRRRRRRRRRMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM: " << std::endl;
	iterator = 0;
	lastval = 1000;
}

// Called repeatedly when this Command is scheduled to run
void AutoArmMove::Execute()
{
	measuredVal = arm->getPosition();
	std::cout << "ARM VALUE: " << measuredVal << std::endl;
	double adjPower = anglePID->Tick(measuredVal);
	arm->move(-adjPower);
	std::cout << "measured encoder value: " << measuredVal << std::endl;
	iterator++;
}

// Make this return true when this Command no longer needs to run execute()
bool AutoArmMove::IsFinished() {
	if(iterator%50 == 0){
				if(fabs(lastval - measuredVal) <0.05){
					return true;
				}
				lastval = measuredVal;
			}

	if(fabs(anglePID->GetError()) < 2 || arm->getArmMotor()->GetSensorCollection().IsRevLimitSwitchClosed())
		return true;
	else
		return false;
}

// Called once after isFinished returns true
void AutoArmMove::End() {
	std::cout << "test auto ending. Error is " << anglePID->GetError() << std::endl;

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoArmMove::Interrupted() {

}

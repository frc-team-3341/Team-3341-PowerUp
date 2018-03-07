#include "MoveLiftToHeight.h"

MoveLiftToHeight::MoveLiftToHeight(double height) :
targetHeight(height),
heightPid(new WVPIDController(1.2, 0, 0, height, false))
{
	Requires(lift);
}

// Called just before this Command runs the first time
void MoveLiftToHeight::Initialize() {
	std::cout << "LIFFFFFFFFFTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT: " << std::endl;
	iterator = 0;
	lastval = 1000;

}

// Called repeatedly when this Command is scheduled to run
void MoveLiftToHeight::Execute()
{
	double power = heightPid->Tick(lift->getHeight());
	std::cout << "power: " << power << std::endl;
	lift->move(lift->Limit(power, 0.6));
	height = lift->getHeight();
	iterator++;
}

// Make this return true when this Command no longer needs to run execute()
bool MoveLiftToHeight::IsFinished() {
	if(iterator%50 == 0){
				if(fabs(lastval - height) <0.05){
					return true;
				}
				lastval = height;
			}
	return fabs(lift->getHeight() - targetHeight) < 0.6;
	//return fabs(heightPid->GetError()) < 0.05;
}

// Called once after isFinished returns true
void MoveLiftToHeight::End() {
	lift->getMotor()->Set(ControlMode::PercentOutput, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveLiftToHeight::Interrupted() {

}

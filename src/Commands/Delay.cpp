#include "Delay.h"



Delay::Delay(double timeout) {

	Requires(drive);
	timer = timeout;

}



void Delay::Initialize() {
	SetTimeout(timer);
}



void Delay::Execute() {
	drive->resetEncoders();
	drive->gyroReset();
}



bool Delay::IsFinished() {

	return IsTimedOut() && fabs(drive->leftDistance()) <= 5 && fabs(drive->rightDistance()) <= 5 && fabs(drive->getAngle()) <= 2;

}



void Delay::End() {

}



void Delay::Interrupted() {

	End();

}

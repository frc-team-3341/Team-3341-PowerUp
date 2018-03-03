#include "DriveForward.h"
#include <iostream>
#include <cmath>
using namespace std;

DriveForward::DriveForward(double _setpoint) : setpoint(_setpoint),
		distancePid(new AutoWVPIDController(distKp, disKi, distKd, setpoint, false)),
		anglePid(new AutoWVPIDController(angleKp, angleKi, angleKd, 0, false)) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drive);
	std::cout << "Autonomous Constructor" << std::endl;

}

// Called just before this Command runs the first time
void DriveForward::Initialize() {
	int i = 0;
	//startDistPidValue = (distancePid->Tick(average))*2.5;
	//std::cout << "Autonomous Initialize" << std::endl;
	/**while(fabs(drive->leftDistance()) >=5 || fabs(drive->rightDistance()) >= 5){
		drive->resetEncoders();
		cout << "SARTHAKLKSJDGJSDKGKLSDJGKL:          " << ++i << endl;
		cout<<"Left: "<<drive->leftDistance()<<" Right:  "<<drive->rightDistance()<<endl;
	}*/
	std::cout << "Encoder Reset" << std::endl;
	drive->gyroReset();
	//std::cout << "Gyro Reset" << std::endl;
	angle = drive->getAngle();
	//std::cout << "Reset works " << std::endl;
	//drive->setStartAbsTicks();
}

// Called repeatedly when this Command is scheduled to run
void DriveForward::Execute() {
	cout<<"Left: "<<drive->leftDistance()<<" Right:  "<<drive->rightDistance()<<endl;

	average = fabs((drive->leftDistance() + drive->rightDistance()) / 2); //change
	double distPidValue = (distancePid->Tick(average))*2.5;

	//double distPidValue = 2*(((distancePid->Tick(average))/(2-distancePid->Tick(average)))*2.5;

	//angle = drive->getAngle();
	cout << "Angle: " << angle << endl;
	//double anglePidValue = anglePid->Tick(angle / 100);

	//drive->arcadeDrive(distPidValue, anglePidValue, 0.5);
	//drive->arcadeDrive(pidValue, 0, 0.2);
	//std::cout << "Value: " << average << std::endl;
	iterator += .2;
	double error = drive->getAngle() - angle;
	cout << "Angle Error: " << error;
	cout << "   Angle: " << drive->getAngle();
	cout << "   Distance: " << average;
	cout<<"Error"<< error<<endl;
	//double multiplier = ;
	if(error > .1) {
		cout << "too much" << endl;
		//drive -> tankDrive(0.5, 0.5);
		/*drive->tankDrive(0.15+ distPidValue + error/15 , 0.15 + distPidValue - error/15);
		std::cout << "Left power More: " << 0.15+ distPidValue + error/15 << std::endl;
		std::cout << "Right power More: " << 0.15 + distPidValue - error/15 << std::endl;*/
		isLeft = true;
		isRight =  false;
	}
	else if (error < -0.1){
		cout << "too less" << endl;
		//drive -> tankDrive(0.5, 0.5);
		/*drive->tankDrive(0.15+ distPidValue - error/15 , 0.15+ distPidValue + error/15);
		std::cout << "Left power Less: " << 0.15+ distPidValue - error/15 << std::endl;
		std::cout << "Right power Less: " << 0.15+ distPidValue + error/15 << std::endl;*/
		isRight = true;
		isLeft = false;
	}
	//isRight = false;
	//isLeft = true;
	cout<<"isRight: "<<isRight<<" isLeft: "<< isLeft<<endl;
	cout<<"distPid: "<<distPidValue<<endl;
	if(isRight){ //isLeft
		//drive->tankDrive(0.2+ distPidValue, 0.2+ distPidValue);
		drive->tankDrive(0.15+ distPidValue + error/10 , 0.15 + fabs(distPidValue) - fabs(error)/10);
		std::cout << "Left power More: " << 0.15+ distPidValue + error/10 << std::endl;
		std::cout << "Right power More: " << 0.15 + fabs(distPidValue)- fabs(error)/10 << std::endl;
	}
	else if(isLeft){ //isRight
		//drive->tankDrive(0.2+ distPidValue, 0.2+ distPidValue);
		drive->tankDrive(0.15+ distPidValue - error/10 , 0.15+ distPidValue + error/10);
		std::cout << "Left power Less: " << 0.15+ distPidValue - error/10 << std::endl;
		std::cout << "Right power Less: " << 0.15+ distPidValue + error/10 << std::endl;
	}
	else {
		drive->tankDrive(0.2+ distPidValue, 0.2+ distPidValue);
		std::cout << "Both power: " << 0.2+ distPidValue << std::endl;
	}

}

// Make this return true when this Command no longer needs to run execute()
bool DriveForward::IsFinished() {
	std::cout << "error is finished VALUE " << fabs(average - setpoint) << std::endl;
	return fabs(average - setpoint) < 3;
}

// Called once after isFinished returns true
void DriveForward::End() {
	std::cout << "error is finished and REACHED END " << fabs(average - setpoint) << std::endl;
	drive->arcadeDrive(0, 0, 0.2);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForward::Interrupted() {

}

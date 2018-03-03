#include "Turn.h"
#include "iostream"
using namespace std;
Turn::Turn(double _setpoint) : setpoint(_setpoint), pid(new AutoWVPIDController(kP, kI, kD, setpoint, false)) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drive);
	std::cout<<"Turn Constructor Successful" <<std::endl;
}
// Called just before this Command runs the first time
void Turn::Initialize() {
	//std::cout<<"Turn Initialize Gyro Reset Successful" <<std::endl;
	drive->gyroReset();
	//drive->resetEncoders();
	//std::cout<<"Turn Initialize Successful" <<std::endl;
}

// Called repeatedly when this Command is scheduled to run
void Turn::Execute() {
	double error = setpoint - drive->getAngle();
	angle = drive->getAngle();
	cout << "Angle: " << angle;
	double anglePID = pid->Tick(angle)/7.5;
	cout<<"AnglePid"<<anglePID<<endl;

		//drive->arcadeDrive(0, anglePID, 0.5);
	if(error<0){
		cout<<"Hello"<<endl;//anglePID/20
		//left
		//drive->tankDrive( -0.3-anglePID/20, 0.4+anglePID/20); --> code for bag n tag robot
		drive->tankDrive(0.5+fabs(anglePID) , -0.5-fabs(anglePID));
		cout << "Right" << 0.5+ fabs(anglePID);
		cout<<"  Left "<< -.5- fabs(anglePID)<<endl;
	}
	else{
		//right
		//drive->tankDrive( 0.3+anglePID/20, -0.15-anglePID/20); --> code for bag n tag robot
		drive->tankDrive(-0.5-fabs(anglePID), 0.5+fabs(anglePID)); //weak,strong increase left constant to allow turn on axis
		cout << "Right" << 0.5+anglePID;
		cout<<"  Left "<< -.5-anglePID<<endl;
	}



	// std::cout << -pid->Tick(angle) << std::endl;
	//negative because turning clockwise gyro returns positive
	//but positive input in arcadedrive turns counterclockwise
}

// Make this return true when this Command no longer needs to run execute()
bool Turn::IsFinished(){

	double error = setpoint - drive->getAngle();
	cout << "   Error: " << error<< endl;
	return fabs(error) < 1.3; //.3
}

// Called once after isFinished returns true
void Turn::End() {
	//drive->resetEncoders();
	//drive->arcadeDrive(0, 0, 0.3);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Turn::Interrupted() {

}

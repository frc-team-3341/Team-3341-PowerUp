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
	iterator = 0;
	lastval = 1000;
	bound = 1.0/3.0*setpoint;
	startPidValue = pid->Tick(setpoint); //2.5
}

// Called repeatedly when this Command is scheduled to run
void Turn::Execute() {
	iterator ++;
	double error = setpoint - drive->getAngle();
	angle = drive->getAngle();
	cout << "Angle: " << angle;
	//double anglePID = pid->Tick(angle)/7.5;
	double anglePID = pid->Tick(angle)/4.0;
	//double anglePID = (pid->Tick((fabs((fabs((error)-bound*startDistPidValue))-bound*startDistPidValue)))); //*2.5

	cout<<"AnglePid"<<anglePID<<endl;
	minimumSpeed = 0.4;
		//drive->arcadeDrive(0, anglePID, 0.5);
	if(error<0){
		cout<<"Hello"<<endl;//anglePID/20
		//left
		//drive->tankDrive( -0.3-anglePID/20, 0.4+anglePID/20); --> code for bag n tag robot
		drive->tankDrive(minimumSpeed +fabs(anglePID) , -minimumSpeed-fabs(anglePID));
		cout << "Right" << minimumSpeed + fabs(anglePID);
		cout<<"  Left "<< -minimumSpeed- fabs(anglePID)<<endl;
		cout << "AnglePID " << anglePID << endl;
	}
	else{
		//right
		//drive->tankDrive( 0.3+anglePID/20, -0.15-anglePID/20); --> code for bag n tag robot
		drive->tankDrive(-minimumSpeed-fabs(anglePID), minimumSpeed+fabs(anglePID)); //weak,strong increase left constant to allow turn on axis
		cout << "Right" << minimumSpeed+anglePID;
		cout<<"  Left "<< -minimumSpeed-anglePID<<endl;
		cout << "AnglePID " << anglePID << endl;
	}

	// std::cout << -pid->Tick(angle) << std::endl;
	//negative because turning clockwise gyro returns positive
	//but positive input in arcadedrive turns counterclockwise
}

// Make this return true when this Command no longer needs to run execute()
bool Turn::IsFinished(){

	if(iterator%20 == 0){
				if(fabs(lastval - angle)<0.05){
					return true;
				}
				lastval = angle;
			}

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

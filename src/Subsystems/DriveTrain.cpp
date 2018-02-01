#include "DriveTrain.h"
#include "../RobotMap.h"
#include "../Commands/TankDrive.h"
#include "iostream"
using namespace std;
#define max(x, y) (((x) > (y)) ? (x) : (y))

DriveTrain::DriveTrain() : Subsystem("DriveTrain"), left(new TalonSRX(LEFTMOTOR)), right(new TalonSRX(RIGHTMOTOR)),
							gyro(new ADXRS450_Gyro()) {


	left->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative,0,10);
	// left->ConfigEncoderCodesPerRev(360);
	left->SetSelectedSensorPosition(0,0,10);
	right->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative,0,10);
	// right->ConfigEncoderCodesPerRev(360);
	right->SetSelectedSensorPosition(0,0,10);

	std::cout<<"DriveTrain Constructor Successful" <<std::endl;
	right->SetInverted(true);
	gyro->Reset();
	gyro->Calibrate();

}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	std::cout<<"DriveTrain InitDefaultCommand Successful" <<std::endl;
	SetDefaultCommand(new TankDrive());
}

double DriveTrain::Limit(double num, double max) {
	if (num > max)
		return max;

	if (num < -max)
		return -max;

	return num;
}

void DriveTrain::tankDrive(double leftVal, double rightVal) {
	left->Set(ControlMode::PercentOutput, DriveTrain::Limit(leftVal, 0.5));
	right->Set(ControlMode::PercentOutput, DriveTrain::Limit(rightVal, 0.5));
}

void DriveTrain::arcadeDrive(double moveVal, double rotateVal) {
	double leftMotorOutput, rightMotorOutput;

/*
	TalonSRX::FeedbackDeviceStatus sensorStatus = left->IsSensorPresent(CANTalon::CtreMagEncoder_Relative);
	TalonSRX::FeedbackDeviceStatus sensorStatus2 = right->IsSensorPresent(CANTalon::CtreMagEncoder_Relative);
	std::cout << "Left, Right: " << sensorStatus << "   " << sensorStatus2 << std::endl;
*/
	// Standard ArcadeDriveTrain algorithm from Google
	if (moveVal > 0.0) {
		if (rotateVal > 0.0) {
			leftMotorOutput = moveVal - rotateVal;
			rightMotorOutput = max(moveVal, rotateVal);
		} else {
			leftMotorOutput = max(moveVal, -rotateVal);
			rightMotorOutput = moveVal + rotateVal;
		}
	} else {
		if (rotateVal > 0.0) {
			leftMotorOutput = -max(-moveVal, rotateVal);
			rightMotorOutput = moveVal + rotateVal;
		} else {
			leftMotorOutput = moveVal - rotateVal;
			rightMotorOutput = -max(-moveVal, -rotateVal);
		}
	}

	left->Set(ControlMode::PercentOutput, DriveTrain::Limit(leftMotorOutput, 0.5));
	right->Set(ControlMode::PercentOutput, DriveTrain::Limit(rightMotorOutput, 0.5));
}

double DriveTrain::getAngle() {
	double angle = gyro->GetAngle();
	//-180 to 180
	while (angle > 180) {
		angle -= 360;
	}
	while (angle < -180) {
		angle += 360;
	}
	return angle;
}

void DriveTrain::gyroReset() {
	gyro->Calibrate();
}

double DriveTrain::leftDistance() { //inches
	double relativePosition = (double) (left->GetSensorCollection().GetPulseWidthPosition() & 0xFFF);
	relativePosition = relativePosition * circumference / 360;
	std::cout<< "Left Wheel Relative Position: " << relativePosition << std::endl;
	return relativePosition;
}

double DriveTrain::rightDistance() { //inches

	double relativePosition = (double) (right->GetSensorCollection().GetPulseWidthPosition() & 0xFFF);
	relativePosition = relativePosition * circumference / 360;
	std::cout<< "Right Wheel Relative Position: " << relativePosition << std::endl;
	return relativePosition;

}
// Put methods for controlling this subsystem
// here. Call these from Commands.

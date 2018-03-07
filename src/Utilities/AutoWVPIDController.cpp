#include "AutoWVPIDController.h"

AutoWVPIDController::AutoWVPIDController(double Kp, double Ki, double Kd,
		double setPoint, bool integralThreshold) :
		lastPWM(0), error(0) {
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
	this->setPoint = setPoint;
	this->integralThreshold = integralThreshold;
	error = 0;
	previousError = 0.0;
	integral = 0.0;
	lastPWM = 0;
}

double AutoWVPIDController::Tick(double measuredValue) {
	error = setPoint - measuredValue;
	//error = measuredValue;
	if (integralThreshold) {
		if (error <= .1)
			integral += error;
	} else
		integral += error;
	double derivative = error - previousError;
	previousError = error;

	lastPWM = Kp * error + Ki * integral + Kd * derivative;
	return lastPWM;
}

void AutoWVPIDController::SetSetPoint(double setPoint) {
	this->setPoint = setPoint;
	integral = 0;
	previousError = 0;
	error = 0;
}

double AutoWVPIDController::GetSetPoint() {
	return setPoint;
}

void AutoWVPIDController::SetKp(double Kp) {
	this->Kp = Kp;
}

double AutoWVPIDController::GetKp() {
	return Kp;
}

void AutoWVPIDController::SetKi(double Ki) {
	this->Ki = Ki;
}

double AutoWVPIDController::GetKi() {
	return Ki;
}

void AutoWVPIDController::SetKd(double Kd) {
	this->Kd = Kd;
}

double AutoWVPIDController::GetKd() {
	return Kd;
}

double AutoWVPIDController::GetError() {
	return error;
}

double AutoWVPIDController::GetLastPWM() {
	return lastPWM;
}

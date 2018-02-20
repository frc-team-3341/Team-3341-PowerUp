#include "WVPIDController.h"

WVPIDController::WVPIDController(double Kp, double Ki, double Kd,
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

double WVPIDController::Tick(double measuredValue) {
	error = setPoint - measuredValue;
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

void WVPIDController::SetSetPoint(double setPoint) {
	this->setPoint = setPoint;
	integral = 0;
	previousError = 0;
	error = 0;
}

double WVPIDController::GetSetPoint() {
	return setPoint;
}

void WVPIDController::SetKp(double Kp) {
	this->Kp = Kp;
}

double WVPIDController::GetKp() {
	return Kp;
}

void WVPIDController::SetKi(double Ki) {
	this->Ki = Ki;
}

double WVPIDController::GetKi() {
	return Ki;
}

void WVPIDController::SetKd(double Kd) {
	this->Kd = Kd;
}

double WVPIDController::GetKd() {
	return Kd;
}

double WVPIDController::GetError() {
	return error;
}

double WVPIDController::GetLastPWM() {
	return lastPWM;
}

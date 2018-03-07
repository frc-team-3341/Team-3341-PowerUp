#ifndef AUTOWVPIDCONTROLLER_H
#define AUTOWVPIDCONTROLLER_H

class AutoWVPIDController {
public:
	AutoWVPIDController(double Kp, double Ki, double Kd, double setPoint,
			bool integralThreshold);
	double Tick(double measuredValue);
	void SetSetPoint(double setPoint);
	double GetSetPoint();
	void SetKp(double Kp);
	double GetKp();
	void SetKi(double Ki);
	double GetKi();
	void SetKd(double Kd);
	double GetKd();
	double GetError();
	double GetLastPWM();

private:

	double Kp;
	double Ki;
	double Kd;
	double setPoint;
	bool integralThreshold;
	double lastPWM;
	double error;
	double previousError;
	double integral;
};

#endif

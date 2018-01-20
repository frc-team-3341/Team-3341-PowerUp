#ifndef PIDCONTROLLER_H
#define PIDCONTROLLER_H

class WVPIDController {
public:
	WVPIDController(double Kp, double Ki, double Kd, double setPoint,
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
	double error;
	double previousError;
	double integral;
	double lastPWM;
};

#endif

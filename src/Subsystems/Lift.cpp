#include "Lift.h"
#include "../RobotMap.h"
#include "../Commands/MoveLift.h"
#include <iostream>

Lift::Lift() : Subsystem("Lift"),
motor(new TalonSRX(LIFT_MOTOR)),
ticksPerDistance(8294),
liftHeight(0)
{
	motor->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative,0,10);
}

Lift::~Lift()
{
	delete motor;
}

void Lift::InitDefaultCommand() {
	SetDefaultCommand(new MoveLift());
}

void Lift::move(double speed)
{
	SmartDashboard::PutNumber("liftHeight",liftHeight);
	motor->Set(ControlMode::PercentOutput, speed);
	std::cout << "Lift encoder position = " << getPosition() << std::endl;
	std::cout << "Lift height = " << getHeight() << std::endl;
}

TalonSRX* Lift::getMotor()
{
	return motor;
}

float Lift::Limit(float num, float max) {
	if (num > max)
		return max;
	if (num < -max)
		return -max;

	return num;
}

void Lift::setHeight(double height)
{
	liftHeight = height;
}

double Lift::getHeight()
{
	double relativePosition = motor->GetSensorCollection().GetQuadraturePosition(); // Return ticks
	liftHeight = (-relativePosition/ticksPerDistance); // 4096 ticks per revolution
	//std::cout<< "Lift Relative Position: " << relativePosition << std::endl;
	return liftHeight;
}

void Lift::resetEncoder()
{
	motor->SetSelectedSensorPosition(0,0,10);
	//motor->GetSensorCollection().SetQuadraturePosition(0,10);
}

void Lift::RobotSetClosedPositionLoop(TalonSRX* talon) {
	std::cout << "Start of ClosedPositionLoop" << std::endl;

	/* lets grab the 360 degree position of the MagEncoder's absolute position */
	int absolutePosition = talon->GetSensorCollection().GetPulseWidthPosition() & 0xFFF; /* mask out the bottom12 bits, we don't care about the wrap arounds */
	/* use the low level API to set the quad encoder signal */
	//_talon->SetEncPosition(absolutePosition);

	/* choose the sensor and sensor direction */
	talon->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Absolute,0,10);
	talon->SetSensorPhase(true);
	talon->SetInverted(false);
	//TODO: replace this? talon->SetSensorDirection(true);

	/* set the peak and nominal outputs, 12V means full */
	//talon->ConfigNominalOutputVoltage(+0., -0.);
	//talon->ConfigPeakOutputVoltage(+12., -12.);
	talon->ConfigPeakCurrentLimit(35,10);
	talon->ConfigPeakCurrentDuration(200,10);
	talon->ConfigContinuousCurrentLimit(30,10);
	talon->EnableCurrentLimit(true);
	//TODO: test
	/* set the allowable closed-loop error,
	 * Closed-Loop output will be neutral within this range.
	 * See Table in Section 17.2.1 for native units per rotation.
	 */
	//talon->SetAllowableClosedLoopErr(0); /* always servo */
	/* set closed loop gains in slot0 */
	//talon->SelectProfileSlot(0);
	talon->SelectProfileSlot(0,0);
	talon->Config_kF(0,0,200);
	talon->Config_kP(0,1,200);
	talon->Config_kI(0,0,200);
	talon->Config_kD(0,0,200);

	//targetPositionRotations = absolutePosition;
	//talon->SetPosition(0.0);
	talon->SetSelectedSensorPosition(0,0,200);
	talon->Set(ControlMode::Position,absolutePosition);
	//talon->SetControlMode(CANSpeedController::kPosition);
	//talon->Set(0.0); /* 50 rotations in either direction */

	std::cout << "error:" << std::endl;
}

double Lift::getPosition()
{
	return motor->GetSensorCollection().GetQuadraturePosition();
}

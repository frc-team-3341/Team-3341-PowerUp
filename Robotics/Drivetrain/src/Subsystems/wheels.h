#ifndef wheels_H
#define wheels_H
#include "WPILib.h"
#include <Commands/Subsystem.h>
#include "ctre/Phoenix.h"
//S#include "ctrlib/CANTalon.h"

class wheels : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon * right;
	Talon * left;
	TalonSRX * leftCAN;


public:
	wheels();
	void InitDefaultCommand();
};

#endif  // wheels_H

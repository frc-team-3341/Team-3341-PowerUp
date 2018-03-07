#ifndef Catcher_H
#define Catcher_H

#include <Commands/Subsystem.h>
#include <WPIlib.h>
//#include "CANTalon.h"
#include "ctre/Phoenix.h"

class Catcher : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	TalonSRX* catcherRight;
	TalonSRX* catcherLeft;
	bool enabled;

public:
	enum Direction
	{
		in = 1,
		out = 2,
	};
	Catcher();
	~Catcher();
	void InitDefaultCommand();
	void CrateIn();
	void CrateOut();
	void Stop();
	bool IsEnabled();
	void Enable();
	void Disable();
	void moveTogether(double speed, Direction catchDirection);
	void moveLeft(double speed, Direction catchDirection);
	void moveRight(double speed, Direction catchDirection);
	double getSpeedLeft();
	double getSpeedright();
};

#endif  // Catcher_H

#ifndef MiddleToSwitch_H
#define MiddleToSwitch_H

#include <Commands/CommandGroup.h>
#include "WPILib.h"
#include "RobotMap.h"
#include "DriveForward.h"
#include "Turn.h"

class MiddleToSwitch : public CommandGroup {
public:
	MiddleToSwitch(char Pos);
};

#endif  // MiddleToSwitch_H

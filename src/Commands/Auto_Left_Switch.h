#ifndef Auto_Left_Switch_H
#define Auto_Left_Switch_H

#include <Commands/CommandGroup.h>
#include "../RobotMap.h"
#include "DriveForward.h"
#include "Turn.h"

class Auto_Left_Switch : public CommandGroup {
public:
	Auto_Left_Switch();
};

#endif  // Auto_Left_Switch_H

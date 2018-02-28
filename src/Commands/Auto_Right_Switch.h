#ifndef Auto_Right_Switch_H
#define Auto_Right_Switch_H

#include <Commands/CommandGroup.h>
#include "../RobotMap.h"
#include "DriveForward.h"
#include "Turn.h"

class Auto_Right_Switch : public CommandGroup {
public:
	Auto_Right_Switch();
};

#endif  // Auto_Right_Switch_H

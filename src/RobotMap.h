#ifndef ROBOTMAP_H
#define ROBOTMAP_H

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.

constexpr int LEFTMOTOR = 3;
constexpr int RIGHTMOTOR = 2;

constexpr int ARMMOTOR = 5;


constexpr int LIFT_MOTOR = 4;
constexpr int CATCH_LEFT_CAN_ID = 6; //actually 3
constexpr int CATCH_RIGHT_CAN_ID = 7; //actually 2
constexpr int CAMERA_CHANNEL = 0;

constexpr double Center_Mass = 6; // fill this in later
constexpr double To_Switch = 168 - 19 + Center_Mass;
constexpr double Mid_Targets = 228.735 - 168;
constexpr double To_Scale = 324 - 228.735;
constexpr double Cross_Field = 231;
constexpr double Forward_Switch = 55.56 - 19 - 16.75 - Center_Mass;
constexpr double Forward_Scale = 41.88 - 19 - 16.75 - Center_Mass;
constexpr double Forward_Mid = 70 - 19 + Center_Mass;
constexpr double Score_Mid = 70 -19 - Center_Mass;
constexpr double Cross_MidL = 54 + 16.75 - 12;
constexpr double Cross_MidR = 54 - 16.75 + 12;




// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int RANGE_FINDER_PORT = 1;
// constexpr int RANGE_FINDER_MODULE = 1;

#endif  // ROBOTMAP_H

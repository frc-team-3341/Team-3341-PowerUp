/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Camera.h"
#include "../RobotMap.h"

Camera::Camera() : Subsystem("ExampleSubsystem"), camera(new Servo(CAMERA_CHANNEL)) {

}

void Camera::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Camera::moveLeft()
{
	camera->SetSpeed(-0.5);
}

void Camera::moveRight()
{
	camera->SetSpeed(0.5);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

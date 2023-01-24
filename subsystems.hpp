/*
Contains all the subsystem device declarations, such as the chassis and drivetrain.
*/
#pragma once
#include "main.h"

extern Controller controller; // The controller

extern std::shared_ptr<ChassisController> chassis; // The chassis
extern std::shared_ptr<XDriveModel> drivetrain; // The drivetrain

extern IMU inertial; // The inertial sensor

extern Motor intake; // The intake motor
extern Motor catapult; // The catapult motor

extern ADIButton limitSwitch; // The limit switch
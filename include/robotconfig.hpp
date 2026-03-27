#pragma once
#include "pros/apix.h"

// Motor groups
extern pros::MotorGroup leftDrive;
extern pros::MotorGroup rightDrive;

// Individual motors   
extern pros::Motor topRoller;
extern pros::Motor intake;

// IMU
extern pros::Imu imu;

// Pneumatics
extern pros::adi::Pneumatics Match_loader;  
extern pros::adi::Pneumatics descore;

// PID functions
void drivePID(double target);
void turnPID(double target);
#include "robotconfig.hpp"

// Motor groups
pros::MotorGroup leftDrive({-18, -20, -19});
pros::MotorGroup rightDrive({3, 2, 4});

//extra motors
pros::Motor topRoller(11);
pros::Motor intake(7);

//imu
 pros::Imu imu(21);

 //pnuematics
 pros::adi::Pneumatics Match_loader('A', false);
 pros::adi::Pneumatics descore('B', false);
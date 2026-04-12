#include "robotconfig.hpp"
#include <cmath>


//tune these values including the ones on line 11-14
// Drive PID constants
double drive_kP = 0.5;
double drive_kI = 0.0;
double drive_kD = 2.5;

// Turn PID constants
double turn_kP = 2.0;
double turn_kI = 0.05;
double turn_kD = 4.5;   //<--- this value is set to 4.5 by defualt so 70 in aut is == to 90 degrees irl currently so its always 20 less


// Reset encoders
void resetDriveEncoders() {
    leftDrive.tare_position();
    rightDrive.tare_position();
}


// Average encoder position
double getDrivePosition() {
    return (leftDrive.get_position() + rightDrive.get_position()) / 2.0;
}


// DRIVE PID
void drivePID(double target) {

    resetDriveEncoders();

    double error = 0;
    double prevError = 0;
    double integral = 0;

    while (true) {

        double pos = getDrivePosition();

        error = target - pos;

        integral += error;

        double derivative = error - prevError;

        double power =
            error * drive_kP +
            integral * drive_kI +
            derivative * drive_kD;

        leftDrive.move(power);
        rightDrive.move(power);

        prevError = error;

        if (fabs(error) < 5) break;

        pros::delay(10);
    }

    leftDrive.move(0);
    rightDrive.move(0);
}


// TURN PID
void turnPID(double target) {

    double error;
    double prevError = 0;
    double integral = 0;
    uint32_t startTime = pros::millis();

    while (true) {

        double heading = imu.get_rotation();

        error = target - heading;

        integral += error;

        double derivative = error - prevError;

        double power =
            error * turn_kP +
            integral * turn_kI +
            derivative * turn_kD;

        leftDrive.move(power);
        rightDrive.move(-power);

        prevError = error;

        if (fabs(error) < 1) break;

        // Timeout after 3 seconds to prevent infinite loop
        if (pros::millis() - startTime > 3000) break;

        pros::delay(10);
    }

    leftDrive.move(0);
    rightDrive.move(0);
}

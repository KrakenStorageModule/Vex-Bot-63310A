/*
The task to control the drivetrain
*/
#include "main.h"

// Ignore the void *_, PROS just needs that for each task
// I guess.
int DrivetrainTask(void *_) {
    while (true) {
        drivetrain->fieldOrientedXArcade(
            controller.getAnalog(ControllerAnalog::leftX),  // Forward speed
            controller.getAnalog(ControllerAnalog::leftX),  // Left/Right speed
            controller.getAnalog(ControllerAnalog::rightX), // Turn speed
            inertial.get() * degree                         // The current orientation
        );

        pros::delay(20); //It will wait 20 ms between each loop
    }

    return 0;
}
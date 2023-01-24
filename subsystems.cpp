/*
The task handling the running of all the subsystems on the bot
*/
#include "main.h"

int SubsystemsTask(void *_) {
    while (true) {
        /*
        Example intake code
        L1 to move intake "forward" (in)
        L2 to move intake "backward" (out)
        */
        if (controller.getDigital(ControllerDigital::L1)) {
            intake.moveVoltage(12000); // Move forward at max voltage
        } else if (controller.getDigital(ControllerDigital::L2)) {
            intake.moveVoltage(-12000); // Move backward at max voltage
        } else {
            intake.moveVoltage(0); // Stop the motor
        }

        // If the limit switch is not pressed, OR R2 is pressed, move down the catapult
        if (!limitSwitch.isPressed() || controller.getDigital(ControllerDigital::R2)) {
            catapult.moveVoltage(12000);
        } else {
            // The limit switch is being pressed AND R2 isnt pressed
            catapult.moveVoltage(0);
        }

        pros::delay(20);
    }
    return 0;
   

}
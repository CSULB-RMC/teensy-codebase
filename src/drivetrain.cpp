#include "sparkMax.h"
#include "drivetrain.h"

Drivetrain::Drivetrain(int left_pin, int right_pin){

    // Set the objects to the corresponding pins
    left_motor.set_motor_pin(left_pin);
    right_motor.set_motor_pin(right_pin);

}

void Drivetrain::move_forward(int speed){

    // Move the motors forwards
    left_motor.move(1,speed);
    right_motor.move(1, speed);

}

void Drivetrain::move_backward(int speed){

    // Move the motors backwards
    left_motor.move(0,speed);
    right_motor.move(0, speed);

}

void Drivetrain::move_neutral(int speed){

    // Make the motors stop
    left_motor.stop();
    right_motor.stop();

}
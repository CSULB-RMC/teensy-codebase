#include "drivetrain.h"

Drivetrain::Drivetrain(int left_pin, int right_pin) : left_motor(), right_motor() {

    // Set the objects to the corresponding pins
    //left_motor.set_motor_pin(left_pin);
    //right_motor.set_motor_pin(right_pin);
    left_motor.attach(left_pin);
    right_motor.attach(right_pin);

}

#ifdef USING_MICROROS
void Drivetrain::dt_left_callback(const void *msgin, void * context) {
    const std_msgs__msg__Int8 * speed = (const std_msgs__msg__Int8 *)msgin;
    Drivetrain * dt = (Drivetrain *)context;

    dt->move_left(speed->data);
}

void Drivetrain::dt_right_callback(const void *msgin, void * context) {
    const std_msgs__msg__Int8 * speed = (const std_msgs__msg__Int8 *)msgin;
    Drivetrain * dt = (Drivetrain *)context;

    dt->move_right(speed->data);
}
#endif

void Drivetrain::move_left(int speed){

    //move the left motor forward if speed positive, backward if negative
    left_motor.write(map(speed, -100, 100, 0, 180));
    /*
    if (speed > 0)
        left_motor.move(1,speed);
    if (speed < 0)
        left_motor.move(0, abs(speed));
    else
        left_motor.stop();
    */

}

void Drivetrain::move_right(int speed){

    //move the left motor forward if speed positive, backward if negative
    right_motor.write(map(speed, -100, 100, 0, 180));
    /*
    if (speed > 0)
        right_motor.move(1,speed);
    if (speed < 0)
        right_motor.move(0, abs(speed));
    else
        right_motor.stop();
    */

}

void Drivetrain::move_neutral(int speed){

    // Make the motors stop
    left_motor.write(90);
    right_motor.write(90);

}
#include "drivetrain.h"

static int max_up_spd = (90 * MAX_MOTOR_PERCENT) + 90;
static int min_up_spd = 90 - (90 * MAX_MOTOR_PERCENT); 

Drivetrain::Drivetrain(int left_pin, int right_pin) : left_motor(), right_motor() {

    // Set the objects to the corresponding pins
    left_motor.set_motor_pin(left_pin);
    right_motor.set_motor_pin(right_pin);
    //left_motor.attach(left_pin);
    //right_motor.attach(right_pin);

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

// Based on the servo library:
// 0 = full-speed forward (180 for left)
// 180 = full-speed backward (0 for left)
// 90 = no movement

void Drivetrain::move_left(int speed){

    //move the left motor forward if speed positive, backward if negative
    //left_motor.write(map(speed, -100, 100, min_up_spd, max_up_spd));
    
    // Decomissioned code utilizing sparkMax
    
    if (speed > 0)
        left_motor.move(1,speed);
    if (speed < 0)
        left_motor.move(0, abs(speed));
    else
        left_motor.stop();
    

}

void Drivetrain::move_right(int speed){

    //move the right motor forward if speed positive, backward if negative
    //right_motor.write(map(speed, -100, 100, max_up_spd, min_up_spd));
    
    
    // Decomissioned code utilizing sparkMax
    
    if (speed > 0)
        right_motor.move(0,speed);
    if (speed < 0)
        right_motor.move(1, abs(speed));
    else
        right_motor.stop();
    

}

void Drivetrain::move_neutral(int speed){

    // Make the motors stop
    //left_motor.write(90);
    //right_motor.write(90);

}
#include "drivetrain.h"

Drivetrain::Drivetrain(int left_pin, int right_pin){

    // Set the objects to the corresponding pins
    left_motor.set_motor_pin(left_pin);
    right_motor.set_motor_pin(right_pin);

    #ifdef USING_MICROROS
    microros_error = false;

    RCCLASSCHECK(rclc_subscription_init_default(&dt_left_sub, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int8), "dt_left"));
    RCCLASSCHECK(rclc_subscription_init_default(&dt_right_sub, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int8), "dt_right"));

    RCCLASSCHECK(rclc_executor_add_subscription_with_context(&executor, &dt_left_sub, &msg, &dt_left_callback, this, ON_NEW_DATA)); //insane person code
    RCCLASSCHECK(rclc_executor_add_subscription_with_context(&executor, &dt_right_sub, &msg, &dt_right_callback, this, ON_NEW_DATA));

    #endif

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
    if (speed > 0)
        left_motor.move(1,speed);
    if (speed < 0)
        left_motor.move(0, abs(speed));
    else
        left_motor.stop();

}

void Drivetrain::move_right(int speed){

    //move the left motor forward if speed positive, backward if negative
    if (speed > 0)
        right_motor.move(1,speed);
    if (speed < 0)
        right_motor.move(0, abs(speed));
    else
        right_motor.stop();

}

void Drivetrain::move_neutral(int speed){

    // Make the motors stop
    left_motor.stop();
    right_motor.stop();

}

#ifdef USING_MICROROS
bool Drivetrain::getError() {
    return microros_error;
}
#endif
#include <Arduino.h>
#include <Servo.h>
#include "spark.h"
#include "regcon.h"

enum rc_state_t {
    RC_DOWN = 0,
    RC_UP,
    RC_RAISE_STOP = 3,
    RC_SIFT,
    RC_SIFT_STOP
};


// Set the objects to the corresponding pins
RegCon::RegCon(int lin_left_pin1, int lin_left_pin2, int lin_right_pin1, int lin_right_pin2, int spark_left_pin, int spark_right_pin) {
    
    // Set the pin connections
    left_linear.set_breakout_pins(lin_left_pin1, lin_left_pin2); 
    right_linear.set_breakout_pins(lin_right_pin1, lin_right_pin2);
    left_conveyer.set_motor_pin(spark_left_pin); 
    right_conveyer.set_motor_pin(spark_right_pin);

    #ifdef USING_MICROROS
    microros_error = false;

    RCCLASSCHECK(rclc_subscription_init_default(&rc_sub, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int8), "dumper_control"));

    RCCLASSCHECK(rclc_executor_add_subscription_with_context(&executor, &rc_sub, &rc_msg, &rc_callback, this, ON_NEW_DATA));
    #endif
}

#ifdef USING_MICROROS
void RegCon::rc_callback(const void* msgin, void * context) {
    const std_msgs__msg__Int8 * move_state = (const std_msgs__msg__Int8 *)msgin;
    RegCon * rc = (RegCon *)context;

    switch(move_state->data) {
        case RC_DOWN:
            rc->linear_down();
            break;
        case RC_UP:
            rc->linear_up();
            break;
        case RC_RAISE_STOP:
            rc->linear_stop();
            break;
        case RC_SIFT:
            rc->conveyor_forward();
            break;
        case RC_SIFT_STOP:
            rc->conveyor_stop();
            break;
    }
}
#endif

// Sets linear actuator inputs based on table in bucket ladder documentation
void RegCon::linear_up() {
    // Send a command to board to move "forwards" (in-context with board)
    left_linear.DRV8871_move(1);
    right_linear.DRV8871_move(1);
}

void RegCon::linear_down() {
    // Send a command to board to move "backwards" (in-context with board)
    left_linear.DRV8871_move(0);
    right_linear.DRV8871_move(0);
}
    
void RegCon::linear_stop() {
    // Send a command to board to stop (in-context with board)
    left_linear.DRV8871_stop();
    right_linear.DRV8871_stop();
}

// Conveyor belt moves forward/backward/stops by calling the equivalent method on both sparks
void RegCon::conveyor_forward() {
    left_conveyer.move(1);
    right_conveyer.move(1);
}

void RegCon::conveyor_backward() {
    left_conveyer.move(0);
    right_conveyer.move(0);
}

void RegCon::conveyor_stop() {
    left_conveyer.stop();
    right_conveyer.stop();
}

#ifdef USING_MICROROS
bool RegCon::getError() {
    return microros_error;
}
#endif
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
RegCon::RegCon(int linears_pin, int spark_left_pin, int spark_right_pin) : left_conveyer(), right_conveyer(), linears() {
    
    // Set the pin connections
    linears.attach(linears_pin);
    linear_down();
    left_conveyer.set_motor_pin(spark_left_pin); 
    right_conveyer.set_motor_pin(spark_right_pin);

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
    linears.write(REG_LIN_UP);
}

void RegCon::linear_down() {
    // Send a command to board to move "backwards" (in-context with board)
    linears.write(REG_LIN_DOWN);
}
    
void RegCon::linear_stop() {
    // Send a command to board to stop (in-context with board)
}

// Conveyor belt moves forward/backward/stops by calling the equivalent method on both sparks
void RegCon::conveyor_forward() {
    left_conveyer.move(1, BAG_REG_SPEED_FORWARD);
    right_conveyer.move(0, BAG_REG_SPEED_BACKWARD);
}

void RegCon::conveyor_backward() {
    left_conveyer.move(0, BAG_REG_SPEED_BACKWARD);
    right_conveyer.move(1, BAG_REG_SPEED_FORWARD);
}

void RegCon::conveyor_stop() {
    left_conveyer.stop();
    right_conveyer.stop();
}

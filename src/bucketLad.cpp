#include "spark.h"
#include "DRV8871.h"
#include "bucketLad.h"

enum bl_state_t {
    BL_DOWN_BACKWARD, // 0
    BL_UP_FORWARD, // 1
    BL_STOP = 3, // 3
    BL_TELE_FORWARD,
    BL_TELE_BACKWARD,
    BL_TELE_STOP
    // why did I skip 2...
};

// Constructor
BucketLadder::BucketLadder(int left_Linear_pin, int right_Linear_pin, int cim_pin, int bag1_pin, int bag2_pin) : left_linear(), right_linear(), mini_CIM(), bag1(), bag2(){

    // Set the pins for the connections
    left_linear.attach(left_Linear_pin);
    right_linear.attach(right_Linear_pin);
    mini_CIM.set_motor_pin(cim_pin);
    bag1.set_motor_pin(bag1_pin);
    bag2.set_motor_pin(bag2_pin);
}

#ifdef USING_MICROROS
void BucketLadder::bl_control_callback(const void *msgin, void * context) {
    const std_msgs__msg__Int8 * move_state = (const std_msgs__msg__Int8 *)msgin;
    BucketLadder * bl = (BucketLadder *)context;

    switch(move_state->data) {
        case BL_DOWN_BACKWARD:
            bl->linear_down();
            break;
        case BL_UP_FORWARD:
            bl->linear_up();
            break;
        case BL_STOP:
            bl->linear_stop();
            break;
        case BL_TELE_FORWARD:
            bl->cim_forward();
            break;
        case BL_TELE_BACKWARD:
            bl->cim_backward();
            break;
        case BL_TELE_STOP:
            bl->cim_stop();
            break;
        default:
            bl->linear_stop();
            bl->cim_stop();
            break;
    }
}

void BucketLadder::bl_dig_callback(const void *msgin, void * context) {
    const std_msgs__msg__Int8 * move_state = (const std_msgs__msg__Int8 *)msgin;
    BucketLadder * bl = (BucketLadder *)context;

    switch(move_state->data) {
        case BL_DOWN_BACKWARD:
            bl->bucket_backward();
            break;
        case BL_UP_FORWARD:
            bl->bucket_forward();
            break;
        case BL_STOP: //fallthrough
        default:
            bl->bucket_stop();
            break;
    }
}
#endif

// Moves Linear Actuators Up
void BucketLadder::linear_up(){

    left_linear.write(180);
    right_linear.write(180);
}

// Moves Linear Actuators Down
void BucketLadder::linear_down(){

    left_linear.write(0);
    right_linear.write(0);
}

// Stops Linear Actuators
void BucketLadder::linear_stop(){

    // As of now there is no way to stop it due to the fact
    // there is no pot or anything to locate its current position
    
    // left_linear.write(90);
    // right_linear.write(90);
}

// Moves Bucketladder in a forward digging motion
void BucketLadder::bucket_forward(){

    bag1.move(1);
    bag2.move(1);
}

// Moves Bucketladder in a backward digging motion
void BucketLadder::bucket_backward(){

    bag1.move(0);
    bag2.move(0);
}

// Stops Bucketladder from digging
void BucketLadder::bucket_stop(){

    bag1.stop();
    bag2.stop();
}

// Moves Buckketladder horizontally forward
void BucketLadder::cim_forward(){

    mini_CIM.move(1);
}

// Moves Buckketladder horizontally forward
void BucketLadder::cim_backward(){
    
    mini_CIM.move(0);
}

// Moves Buckketladder horizontally forward
void BucketLadder::cim_stop(){

    mini_CIM.stop();
}
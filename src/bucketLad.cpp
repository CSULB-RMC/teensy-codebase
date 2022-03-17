#include "spark.h"
#include "DRV8871.h"
#include "bucketLad.h"

// Constructor
BucketLadder::BucketLadder(int left_Linear_pin1, int left_Linear_pin2, int right_Linear_pin1, int right_Linear_pin2, int cim_pin, int bag1_pin, int bag2_pin){

    // Set the pins for the connections
    left_linear.set_breakout_pins(left_Linear_pin1, left_Linear_pin2);
    right_linear.set_breakout_pins(right_Linear_pin1, right_Linear_pin2);
    mini_CIM.set_motor_pin(cim_pin);
    bag1.set_motor_pin(bag1_pin);
    bag2.set_motor_pin(bag2_pin);
}

// Moves Linear Actuators Up
void BucketLadder::linear_up(){

    left_linear.DRV8871_move(1);
    right_linear.DRV8871_move(1);
}

// Moves Linear Actuators Down
void BucketLadder::linear_down(){

    left_linear.DRV8871_move(0);
    right_linear.DRV8871_move(0);
}

// Stops Linear Actuators
void BucketLadder::linear_stop(){

    left_linear.DRV8871_stop();
    right_linear.DRV8871_stop();
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

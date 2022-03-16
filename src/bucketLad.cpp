#include "spark.h"
#include "DRV8871.h"
#include "bucketLad.h"

// Constructor
BucketLadder::BucketLadder(int left_Linear_pin1, int left_Linear_pin2, int right_Linear_pin1, int right_Linear_pin2, int cim_pin, int bag1_pin, int bag2_pin){

    // Set the pins for the connections
    set_lin_pins(left_Linear_pin1, left_Linear_pin2, right_Linear_pin1, right_Linear_pin2);
    set_cim_pins(cim_pin);
    set_spark_pins(bag1_pin, bag2_pin);

}

// Sets the Linear Actuator pins
void BucketLadder::set_lin_pins(int l_pin1, int l_pin2, int r_pin1, int r_pin2){

    left_linear.set_breakout_pins(l_pin1, l_pin2);
    right_linear.set_breakout_pins(r_pin1, r_pin2);

}

// Sets the CIM motor pins
void BucketLadder::set_cim_pins(int cim_pin){

    mini_CIM.set_motor_pin(cim_pin);

}

// Sets the BAG motors to the sparks
void BucketLadder::set_spark_pins(int bag1_pin, int bag2_pin){

    bag1.set_motor_pin(bag1_pin);
    bag2.set_motor_pin(bag2_pin);

}
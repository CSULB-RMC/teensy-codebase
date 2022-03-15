#include <Arduino.h>
#include <Servo.h>
#include "spark.h"
#include "regcon.h"

// Set the objects to the corresponding pins
RegCon::RegCon(int lin_left_pin1, int lin_left_pin2, int lin_right_pin1, int lin_right_pin2, int spark_left_pin, int spark_right_pin) {
    set_lin_pins(lin_left_pin1, lin_left_pin2, lin_right_pin1, lin_right_pin2);
    set_spark_pins(spark_left_pin, spark_right_pin);
}

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

// Sets linear actuator pins
void RegCon::set_lin_pins(int l_pin1, int l_pin2, int r_pin1, int r_pin2) {
    left_linear.set_breakout_pins(l_pin1, l_pin2);
    right_linear.set_breakout_pins(r_pin1, r_pin2);
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

// Sets pins for sparks
void RegCon::set_spark_pins(int l_pin, int r_pin) {
    left_conveyer.set_motor_pin(l_pin);
    right_conveyer.set_motor_pin(r_pin);
}
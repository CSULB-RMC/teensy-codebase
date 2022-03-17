#include <Arduino.h>
#include <Servo.h>
#include "spark.h"
#include "regcon.h"

// Set the objects to the corresponding pins
RegCon::RegCon(int lin_left_pin1, int lin_left_pin2, int lin_right_pin1, int lin_right_pin2, int spark_left_pin, int spark_right_pin) {
    
    // Set the pin connections
    left_linear.set_breakout_pins(lin_left_pin1, lin_left_pin2); 
    right_linear.set_breakout_pins(lin_right_pin1, lin_right_pin2);
    left_conveyer.set_motor_pin(spark_left_pin); 
    right_conveyer.set_motor_pin(spark_right_pin);
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

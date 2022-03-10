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
    set_lin_inputs(1, 0, 1, 0);
}

void RegCon::linear_down() {
    set_lin_inputs(0, 1, 0, 1);
}
    
void RegCon::linear_stop() {
    set_lin_inputs(1, 1, 1, 1);
}

// Sets linear actuator pins
void RegCon::set_lin_pins(int l_pin1, int l_pin2, int r_pin1, int r_pin2) {
    pinMode(l_pin1, OUTPUT);
    pinMode(l_pin2, OUTPUT);
    pinMode(r_pin1, OUTPUT);
    pinMode(r_pin2, OUTPUT);
}

// Sets linear actuator inputs
void RegCon::set_lin_inputs(int l_input1, int l_input2, int r_input1, int r_input2) {
    digitalWrite(lin_left1, l_input1);
    digitalWrite(lin_left2, l_input2);
    digitalWrite(lin_right1, r_input1);
    digitalWrite(lin_right2, r_input2);
}

// Conveyor belt moves forward/backward/stops by calling the equivalent method on both sparks
void RegCon::conveyor_forward() {
    left_spark.spark_forward();
    right_spark.spark_forward();
}

void RegCon::conveyor_backward() {
    left_spark.spark_backward();
    right_spark.spark_backward();
}

void RegCon::conveyor_stop() {
    left_spark.spark_neutral();
    right_spark.spark_neutral();
}

// Sets pins for sparks
void RegCon::set_spark_pins(int l_pin, int r_pin) {
    left_spark.set_motor_pin(l_pin);
    right_spark.set_motor_pin(r_pin);
}
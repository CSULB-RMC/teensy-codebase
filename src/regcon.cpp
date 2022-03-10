#include <Servo.h>
#include "spark.h"
#include "regcon.h"

// Set the objects to the corresponding pins
RegCon::RegCon(int pin1, int pin2) {
    left_spark.set_motor_pin(pin1);
    right_spark.set_motor_pin(pin2);
}

// TODO
void RegCon::linear_up() {

}

void RegCon::linear_down() {

}
    
void RegCon::linear_stop() {

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
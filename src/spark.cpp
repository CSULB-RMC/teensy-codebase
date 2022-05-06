#include "spark.h"
#include "config.h"

// Spark (bag motor) constructor
Spark::Spark(int pin_num){
    
    // Set the pin number of the motor
    set_motor_pin(pin_num);

    // Set the speed of the motor to neutral
    spark_neutral();
}

// Goes from 0 to 180, 90 is neutral, 0 is backwards, and 180 is forwards
void Spark::spark_forward(int speed) {
    // spark_dir = FORWARD;
    servo.write(speed);
}

void Spark::spark_backward(int speed) {
    // spark_dir = BACKWARD;
    servo.write(speed);
}

void Spark::spark_neutral() {
    // spark_dir = NEUTRAL;
    servo.write(90);
}

// This method attaches the motor pin to the bag motor
void Spark::set_motor_pin(int pin_num) {
    
    // Record the pin location
    spark_pin = pin_num;

    // Attach the pin
    servo.attach(pin_num);
}

// Backward = 0, Forwards = 1
void Spark::move(int direction, int speed){

    // If direction is 1...
    if(direction){

        spark_forward(speed);
    }

    else{

        spark_backward(speed);
    }
}

// Stops the sparks
void Spark::stop(){

    spark_neutral();
}
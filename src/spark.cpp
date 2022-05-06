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
void Spark::spark_forward() {
    spark_dir = FORWARD;
    servo.write(spark_dir);
}

void Spark::spark_backward() {
    spark_dir = BACKWARD;
    servo.write(spark_dir);
}

void Spark::spark_neutral() {
    spark_dir = NEUTRAL;
    servo.write(spark_dir);
}

// This method attaches the motor pin to the bag motor
void Spark::set_motor_pin(int pin_num) {
    
    // Record the pin location
    spark_pin = pin_num;

    // Attach the pin
    servo.attach(pin_num);
}

// Backward = 0, Forwards = 1
void Spark::move(int direction){

    // If direction is 1...
    if(direction){

        spark_forward();
    }

    else{

        spark_backward();
    }
}

// Stops the sparks
void Spark::stop(){

    spark_neutral();
}
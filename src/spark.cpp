#include "spark.h"
#include "config.h"

// Spark (bag motor) constructor
Spark::Spark(int pin_num){
    
    // Set the pin number of the motor
    set_motor_pin(pin_num);

    // Set the speed of the motor to neutral
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
void Spark::move(int speed){

    // Set the speed
    servo.write(speed);
}

// Stops the sparks
void Spark::stop(){

    servo.write(90);
}
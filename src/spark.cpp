#include "spark.h"

// Spark (bag motor) constructor
Spark::Spark(int pin_num){
    
    // Set the pin number of the motor
    servo.attach(pin_num);

    // Set the speed of the motor to neutral
    spark_neutral();
}

// Goes from 0 to 180, 90 is neutral
void Spark::spark_forward() {
    servo.write(180);
}

void Spark::spark_backward() {
    servo.write(0);
}

void Spark::spark_neutral() {
    servo.write(90);
}
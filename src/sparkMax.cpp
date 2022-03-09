#include "sparkMax.h"
#include <Arduino.h>

// SparkMax motor driver constructor
SparkMax::SparkMax(int pin_num){
    
    // Set the pin number of the motor
    set_motor_pin(pin_num);

    // Set the speed of the motor to neutral
    spark_neutral();
}

// Set the pin of the motor PWM
void SparkMax::set_motor_pin(int pin){
   
    // Records the new motor PWM pin
    motor_PWM_pin = pin;

    // Updates the pinMode of the motor PWM output
    pinMode(motor_PWM_pin, OUTPUT);
}

// Makes the motor move forward
void SparkMax::spark_forward(int speed){

    // Save the speed and direction
    current_speed = speed;
    current_direction = 1;

    // Coversion of speed percentage to analog
    PWM_speed_div = map(speed, 0, 100, min_forward, max_forward);

    // Set the speed
    analogWrite(motor_PWM_pin, PWM_speed_div);
}

// Makes motor move backwards
void SparkMax::spark_backwards(int speed){

    // Save the speed and direction
    current_speed = speed;
    current_direction = 0;

    // Coversion of speed percentage to analog
    PWM_speed_div = map(speed, 0, 100, min_backward, max_backward);

    // Set the speed
    analogWrite(motor_PWM_pin, PWM_speed_div);
}

// Makes motor stop or not move
void SparkMax::spark_neutral(){

    // Save the speed and direction
    current_speed = 0;
    current_direction = 3;

    // Set the speed
    analogWrite(motor_PWM_pin, 0);
}

// Inputs:
// Direction (0 = Backwards, 1 = Forwards)
// Speed (0 to 100 integer)
void SparkMax::move(int direction, int speed_percent){

    // If we wish to go forwards,
    if(direction){

        // Send PWM signal to go forwards
        spark_forward(speed_percent);

    }

    // Otherwise go backwards
    else{
        
        // Send PWM signal to go backwards
        spark_backwards(speed_percent);
    }

}
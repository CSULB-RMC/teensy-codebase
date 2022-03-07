#include "drivetrain.h"
#include <Arduino.h>

// Drivetrain constructor
Drivetrain::Drivetrain(int pin_num){
    
    // Set the pint number of the motor
    set_drivetrain_pin(pin_num);

    // Set the speed of the motor to neutral
    drivetrain_neutral();
}

// Set the pin of the drivetrain PWM
void Drivetrain::set_drivetrain_pin(int pin){
   
    // Set the desired pin of the drivetrain motor PWM output
    pinMode(pin, OUTPUT);
}

void Drivetrain::drivetrain_forward(int speed){

    // Save the speed and direction
    current_speed = speed;
    current_direction = 1;

    // Coversion of speed percentage to analog
    PWM_speed_div = map(speed, 0, 100, min_forward, max_forward);

    // Set the speed
    analogWrite(drivetrain_pin, PWM_speed_div);
}

void Drivetrain::drivetrain_backwards(int speed){

    // Save the speed and direction
    current_speed = speed;
    current_direction = 0;

    // Coversion of speed percentage to analog
    PWM_speed_div = map(speed, 0, 100, min_backward, max_backward);

    // Set the speed
    analogWrite(drivetrain_pin, PWM_speed_div);
}

void Drivetrain::drivetrain_neutral(){

    // Save the speed and direction
    current_speed = 0;
    current_direction = 3;

    // Set the speed
    analogWrite(drivetrain_pin, 0);
}

// Inputs:
// Direction (0 = Backwards, 1 = Forwards)
// Speed (0 to 100 integer)
void Drivetrain::move(int direction, int speed_percent){

    // If we wish to go forwards,
    if(direction){

        // Send PWM signal to go forwards
        drivetrain_forward(speed_percent);

    }

    // Otherwise go backwards
    else{
        
        // Send PWM signal to go backwards
        drivetrain_backwards(speed_percent);
    }

}
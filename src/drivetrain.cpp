#include "drivetrain.h"
#include <Arduino.h>

// Drivetrain constructor
Drivetrain::Drivetrain(int pin_num){
    
    // Set the pint number of the motor
    set_drivetrain_pin(pin_num);

    // Set the speed of the motor to neutral

}

// Set the pin of the drivetrain PWM
void Drivetrain::set_drivetrain_pin(int pin){

    pinMode(pin, OUTPUT);

}


void Drivetrain::set_speed(int speed){}

// Inputs:
// Direction (0 = Backwards, 1 = Forwards)
// Speed (0 to 100 integer)
void Drivetrain::move(int direction, int speed_percent){



}
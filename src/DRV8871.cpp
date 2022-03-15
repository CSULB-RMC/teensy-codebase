#include "DRV8871.h"
#include <Arduino.h>

// Constructor method for class
DRV8871::DRV8871(int lin1, int lin2){

    // Set the pin location
    set_breakout_pins(lin1, lin2);

    // Set the driver for stop
    DRV8871_stop();
}


// Sends command to run motor in Positive Bias
void DRV8871::forward(){
    
    // Change the current direction output variables
    lin1_dir = 1;
    lin2_dir = 0;

    // Output the desired direction to breakout
    set_output(lin1_dir, lin2_dir);
}

// Sends command to run motor in Negative Bias
void DRV8871::backward(){

    // Change the current direction output variables
    lin1_dir = 0;
    lin2_dir = 1;

    // Output the desired direction to breakout
    set_output(lin1_dir, lin2_dir);
}

// Stop the motors
void DRV8871::stop(){

    // Change the current direction output variables
    lin1_dir = 1;
    lin2_dir = 1;

    // Output the desired direction to breakout
    set_output(lin1_dir, lin2_dir);
}


// Sends a digital signal (1 or 0) to corresponding ports towards the breakout
void DRV8871::set_output(int lin1, int lin2){

    digitalWrite(lin1_pin, lin1);
    digitalWrite(lin2_pin, lin2);
}

// Direction can be backwards(0), and forwards(1) 
void DRV8871::DRV8871_move(int direction){

    // If direction is 1 (forward)
    if(direction){

        // Send command to move forward
        forward();
    }

    else{
        // Send command to move backwards
        backward();
    }
}

// Tells the motor to stop
void DRV8871::DRV8871_stop(){
    stop();
}

// Changes location definiton of pin output on Teensy
void DRV8871::set_breakout_pins(int lin1, int lin2){
    
    // Record new pin positions
    lin1_pin = lin1;
    lin2_pin = lin2;

    // Set new pin definitions
    pinMode(lin1_pin, OUTPUT);
    pinMode(lin2_pin, OUTPUT);
}

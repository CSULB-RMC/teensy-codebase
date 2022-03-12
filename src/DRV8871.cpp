#include "DRV8871.h"
#include <Arduino.h>

// Sends command to run motor in Positive Bias
void DRV8871::forward(){
    
    // Change the current direction output variables
    lin_left1_dir = 1;
    lin_left2_dir = 0;
    lin_right1_dir = 1;
    lin_right2_dir = 0;

    // Output the desired direction to breakout
    set_output(lin_left1_dir, lin_left2_dir,
                lin_right1_dir, lin_right2_dir);
}

// Sends command to run motor in Negative Bias
void DRV8871::backward(){

    // Change the current direction output variables
    lin_left1_dir = 0;
    lin_left2_dir = 1;
    lin_right1_dir = 0;
    lin_right2_dir = 1;

    // Output the desired direction to breakout
    set_output(lin_left1_dir, lin_left2_dir,
                lin_right1_dir, lin_right2_dir);
}

// Stop the motors
void DRV8871::stop(){

    // Change the current direction output variables
    lin_left1_dir = 1;
    lin_left2_dir = 1;
    lin_right1_dir = 1;
    lin_right2_dir = 1;

    // Output the desired direction to breakout
    set_output(lin_left1_dir, lin_left2_dir,
                lin_right1_dir, lin_right2_dir);
}


// Sends a digital signal (1 or 0) to corresponding ports towards the breakout
void DRV8871::set_output(int linL1, int linL2, int linR1, int linR2){

    digitalWrite(lin_left1_pin, linL1);
    digitalWrite(lin_left2_pin, linL2);
    digitalWrite(lin_right1_pin, linR1);
    digitalWrite(lin_right2_pin, linR2);
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
void DRV8871::set_linear_pins(int L_lin1, int L_lin2, int R_lin1, int R_lin2){
    
    // Record new pin positions
    lin_left1_pin = L_lin1;
    lin_left2_pin = L_lin2;
    lin_right1_pin = R_lin1;
    lin_right2_pin = R_lin2;


    // Set new pin definitions
    pinMode(lin_left1_pin, OUTPUT);
    pinMode(lin_left2_pin, OUTPUT);
    pinMode(lin_right1_pin, OUTPUT);
    pinMode(lin_right2_pin, OUTPUT);
}

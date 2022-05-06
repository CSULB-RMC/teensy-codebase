#ifndef SPARK_H
#define SPARK_H

#include <Servo.h>

// Motor controller for bag motor (controls the sifter conveyers)
class Spark {

private:
    // Variables for reference
    int spark_pin,
        spark_dir;

    // Built in servo library
    Servo servo;

    // Motor methods
    void spark_forward();
    void spark_backward();
    void spark_neutral();

public:
    // Constructor, parameter for pin number
    Spark(int=0);

    // Function for moving 
    void move(int);
    
    // Method for stopping the motors
    void stop();

    // Setter for motor pin number
    void set_motor_pin(int);
};

#endif
#ifndef SPARK_H
#define SPARK_H

#include <Servo.h>

// Motor controller for bag motor
class Spark {

private:
    // Built in servo library
    Servo servo;

public:
    // Constructor, parameter for pin number
    Spark(int=0);

    // Motor methods
    void spark_forward();
    void spark_backward();
    void spark_neutral();

    // Setter for motor pin number
    void set_motor_pin(int);
};

#endif
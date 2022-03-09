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
    Spark(int);

    // Motor methods
    void spark_forward();
    void spark_backward();
    void spark_neutral();
};

#endif
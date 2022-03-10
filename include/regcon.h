#ifndef REGCON_H
#define REGCON_H

#include <Servo.h>
#include "spark.h"

class RegCon {
private:
    // Spark objects for bag motors for conveyor
    Spark left_spark;
    Spark right_spark;
    
public:
    // Constructor
    // Parameters are for spark pins, not thinking bout liner actuators for now
    RegCon(int, int); 

    // Linear actuator methods, uses two linear actuators
    void linear_up();
    void linear_down();
    void linear_stop();

    // Conveyor methods, uses two bag motors
    void conveyor_forward();
    void conveyor_backward();
    void conveyor_stop();
};

#endif
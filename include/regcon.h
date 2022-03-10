#ifndef REGCON_H
#define REGCON_H

#include <Servo.h>
#include "spark.h"

class RegCon {
private:
    int lin_left1;
    int lin_left2;
    int lin_right1;
    int lin_right2;

    // Spark objects for bag motors for conveyor
    Spark left_spark;
    Spark right_spark;
    
public:
    // Constructor
    // Parameters are for spark pins, not thinking bout liner actuators for now
    RegCon(int, int, int, int, int, int); 

    // Linear actuator methods, uses two linear actuators
    void linear_up();
    void linear_down();
    void linear_stop();

    // Setter methods for linear actuator
    void set_lin_pins(int, int, int, int);
    void set_lin_inputs(int, int, int, int);

    // Conveyor methods, uses two bag motors
    void conveyor_forward();
    void conveyor_backward();
    void conveyor_stop();

    // Setter methods for conveyor sparks
    void set_spark_pins(int, int);
};

#endif
#ifndef REGCON_H
#define REGCON_H

#include "spark.h"
#include "DRV8871.h"

class RegCon {
private:
    // Spark objects for bag motors for conveyor
    Spark left_conveyer;
    Spark right_conveyer;

    // DRV8871 breakout board objects for linear actuators
    DRV8871 left_linear;
    DRV8871 right_linear;
    
public:
    // Constructor
    // Parameters are for spark pins, not thinking bout liner actuators for now
    RegCon(int=0, int=0, int=0, int=0, int=0, int=0); 

    // Linear actuator methods, uses two linear actuators
    void linear_up();
    void linear_down();
    void linear_stop();

    // Setter methods for linear actuator
    void set_lin_pins(int, int, int, int);

    // Conveyor methods, uses two bag motors
    void conveyor_forward();
    void conveyor_backward();
    void conveyor_stop();

    // Setter methods for conveyor sparks
    void set_spark_pins(int, int);
};

#endif
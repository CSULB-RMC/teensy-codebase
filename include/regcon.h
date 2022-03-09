#ifndef REGCON_H
#define REGCON_H

#include <Servo.h>
#include "spark.h"

class RegCon {
    
public:
    //constructor
    //parameters for spark pins, not thinking bout liner actuators for now
    RegCon(int, int); 

    //linear actuator methods, two linear actuators
    void linear_up();
    void linear_down();
    void linear_stop();

    //conveyor methods, two bag motors
    void conveyor_forward();
    void conveyor_backward();
    void conveyor_stop();
};

#endif
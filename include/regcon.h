#ifndef REGCON_H
#define REGCON_H

#include "spark.h"
#include <Servo.h>

#include "config.h"

#ifdef USING_MICROROS
#include "microros_setup.h"
#include <std_msgs/msg/int8.h>
#endif

class RegCon {
    private:
        // Spark objects for bag motors for conveyor
        Spark left_conveyer;
        Spark right_conveyer;

        // DRV8871 breakout board objects for linear actuators
        Servo linears;
        
    public:
        // Constructor
        // Parameters are for spark pins, not thinking bout liner actuators for now
        RegCon(int linears_pin = 0, int spark_left_pin = 0, int spark_right_pin = 0); 

        // Linear actuator methods, uses two linear actuators
        void linear_up();
        void linear_down();
        void linear_stop();

        // Conveyor methods, uses two bag motors
        void conveyor_forward();
        void conveyor_backward();
        void conveyor_stop();

        #ifdef USING_MICROROS
        static void rc_callback(const void *msgin, void * context);
        #endif
};

#endif
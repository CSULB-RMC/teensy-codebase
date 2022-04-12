#ifndef REGCON_H
#define REGCON_H

#include "spark.h"
#include "DRV8871.h"

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
        DRV8871 left_linear;
        DRV8871 right_linear;

        #ifdef USING_MICROROS
        bool microros_error;

        rcl_subscription_t rc_sub;

        std_msgs__msg__Int8 rc_msg;

        static void rc_callback(const void *msgin, void * context);
        #endif
        
    public:
        // Constructor
        // Parameters are for spark pins, not thinking bout liner actuators for now
        RegCon(int=0, int=0, int=0, int=0, int=0, int=0); 

        // Linear actuator methods, uses two linear actuators
        void linear_up();
        void linear_down();
        void linear_stop();

        // Conveyor methods, uses two bag motors
        void conveyor_forward();
        void conveyor_backward();
        void conveyor_stop();

        #ifdef USING_MICROROS
        bool getError();
        #endif
};

#endif
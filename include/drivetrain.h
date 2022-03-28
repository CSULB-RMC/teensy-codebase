#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "sparkMax.h"
#include "config.h"

#ifdef USING_MICROROS
#include "microros_setup.h"
#include <std_msgs/msg/int8.h>
#endif

class Drivetrain{    

    private:
        // Initialize SparkMax objects
        SparkMax left_motor;
        SparkMax right_motor;

        #ifdef USING_MICROROS
        bool microros_error;

        rcl_subscription_t dt_left_sub;
        rcl_subscription_t dt_right_sub;

        std_msgs__msg__Int8 msg;

        static void dt_left_callback(const void *msgin, void * context);
        static void dt_right_callback(const void *msgin, void * context);
        #endif
    
    public:
        // Constructor 
        Drivetrain(int=0, int=0);

        // Movement functions for the Drivetrain
        void move_left(int=0);
        void move_right(int=0);
        void move_neutral(int=0);

        #ifdef USING_MICROROS
        bool getError();
        #endif
};

#endif
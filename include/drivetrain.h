#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
//#include <Servo.h>
#include "config.h"
#include "sparkMax.h"

#ifdef USING_MICROROS
#include "microros_setup.h"
#include <std_msgs/msg/int8.h>
#endif

class Drivetrain{    

    private:
        // Initialize Servo objects
        SparkMax left_motor;
        SparkMax right_motor;
    
    public:
        // Constructor 
        Drivetrain(int=0, int=0);

        // Movement functions for the Drivetrain
        void move_left(int=0);
        void move_right(int=0);
        void move_neutral(int=0);

        #ifdef USING_MICROROS
        static void dt_left_callback(const void *msgin, void * context);
        static void dt_right_callback(const void *msgin, void * context);
        #endif
};

#endif
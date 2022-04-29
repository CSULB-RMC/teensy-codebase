#ifndef BUCKETLAD_H
#define BUCKETLAD_H

#include "spark.h"
#include <Servo.h>

#include "config.h"

#ifdef USING_MICROROS
#include "microros_setup.h"
#include <std_msgs/msg/int8.h>
#endif

class BucketLadder{

    private:
        // Linear actuator class objects
        Servo left_linear;
        Servo right_linear;

        // Motor instantiation
        Spark mini_CIM;
        Spark bag1, bag2;

    public:
        // Constructor
        BucketLadder(int=0, int=0, int=0, int=0, int=0);

        // Linear actuator methods
        void linear_up();
        void linear_down();
        void linear_stop();

        // Digging method (BAG motors)
        void bucket_forward();
        void bucket_backward();
        void bucket_stop();

        // Extension/Retraction (Horizontal)
        void cim_forward();
        void cim_backward();
        void cim_stop();

        #ifdef USING_MICROROS
        static void bl_control_callback(const void *msgin, void * context);
        static void bl_dig_callback(const void *msgin, void * context);
        #endif
};  


#endif
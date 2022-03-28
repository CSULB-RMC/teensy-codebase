#ifndef BUCKETLAD_H
#define BUCKETLAD_H

#include "spark.h"
#include "DRV8871.h"

#include "config.h"

#ifdef USING_MICROROS
#include "microros_setup.h"
#include <std_msgs/msg/int8.h>
#endif

class BucketLadder{

    private:
        // Linear actuator class objects
        DRV8871 left_linear;
        DRV8871 right_linear;

        // Motor instantiation
        Spark mini_CIM;
        Spark bag1, bag2;

        #ifdef USING_MICROROS
        bool microros_error;

        rcl_subscription_t bl_lift_sub;
        rcl_subscription_t bl_tele_sub;
        rcl_subscription_t bl_dig_sub;

        std_msgs__msg__Int8 bl_lift_msg;
        std_msgs__msg__Int8 bl_tele_msg;
        std_msgs__msg__Int8 bl_dig_msg;

        static void bl_lift_callback(const void *msgin, void * context);
        static void bl_tele_callback(const void *msgin, void * context);
        static void bl_dig_callback(const void *msgin, void * context);
        #endif

    public:
        // Constructor
        BucketLadder(int=0, int=0, int=0, int=0, int=0, int=0, int=0);

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
        bool getError();
        #endif
};  


#endif
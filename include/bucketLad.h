#ifndef BUCKETLAD_H
#define BUCKETLAD_H

#include "spark.h"
#include "DRV8871.h"

class BucketLadder{

    private:
        // Linear actuator class objects
        DRV8871 left_linear;
        DRV8871 right_linear;

        // Motor instantiation
        Spark mini_CIM;
        Spark bag1, bag2;

    public:
        // Constructor
        BucketLadder(int=0, int=0, int=0, int=0, int=0, int=0, int=0);

        // Linear actuator methods
        void linear_up();
        void linear_down();
        void linear_stop();

        // Set Linear actuator pins
        void set_lin_pins(int, int, int, int);

        // Digging method (BAG motors)
        void bucket_forward();
        void bucket_backward();
        void bucket_stop();

        // Set BAG motor pins
        void set_spark_pins(int, int);

        // Extension/Retraction (Horizontal)
        void cim_forward();
        void cim_backward();
        void cim_stop();
        
        // Set CIM motor pin
        void set_cim_pins(int);
};  


#endif
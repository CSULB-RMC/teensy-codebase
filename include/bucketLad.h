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

        // Digging method (BAG motors)
        void bucket_forward();
        void bucket_backward();
        void bucket_stop();

        // Extension/Retraction (Horizontal)
        void cim_forward();
        void cim_backward();
        void cim_stop();
};  


#endif
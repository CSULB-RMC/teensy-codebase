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


};


#endif
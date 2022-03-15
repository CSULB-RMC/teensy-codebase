#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "sparkMax.h"

class Drivetrain{    

    private:
        // Initialize SparkMax objects
        SparkMax left_motor;
        SparkMax right_motor;
    
    public:
        // Constructor 
        Drivetrain(int=0, int=0);

        // Movement functions for the Drivetrain
        void move_forward(int=0);
        void move_backward(int=0);
        void move_neutral(int=0);
};

#endif
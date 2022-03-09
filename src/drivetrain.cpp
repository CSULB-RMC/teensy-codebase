#include "sparkMax.h"
#include "drivetrain.h"

Drivetrain::Drivetrain(int left_motor, int right_motor){

    // Call the sparkMax motor constructors and pass in the pins
    SparkMax Left_Motor(left_motor);
    SparkMax Right_Motor(right_motor);
}
#ifndef SPARKMAX_H
#define SPARKMAX_H

class SparkMax{

private:

    // Pin, Freq, Speed division definitions
    const int PWM_Frequency = 100,
              min_forward = 39,
              max_forward = 51,
              neutral_spd = 38,
              min_backward = 25,
              max_backward = 37;

    // Drivetrain stats
    int motor_PWM_pin = 0,
        current_speed = 0,
        PWM_speed_div = 0,
        current_direction = 0;

    // Setter functions
    void set_motor_pin(int);

    // Drivetrain driver
    void spark_forward(int);
    void spark_backwards(int);
    void spark_neutral();

    // Future implementations
    // Read encoder (to assist with finding speed)

public:

    // Class instantiation (set the pin of the drivetrain)
    SparkMax(int);

    // Proportional forwards/backwards w/ setting speed
    void move(int, int);

};

#endif
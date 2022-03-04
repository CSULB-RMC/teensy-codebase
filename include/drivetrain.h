#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

class Drivetrain{

private:

    // Pin, Freq, Speed division definitions
    const int PWM_Frequency = 100,
              min_forward = 39,
              max_forward = 51,
              neutral_spd = 38,
              min_backward = 25,
              max_backward = 37;

    // Pin location of drivetrain motor
    int drivetrain_pin = 0;

    // Setter functions
    void set_drivetrain_pin(int);
    void set_speed(int);

    // Drivetrain driver
    void drivetrain_forward(int);
    void drivetrain_backwards(int);
    void drivetrain_neutral();

    // Future implementations
    // Read encoder (to assist with finding speed)

public:

    // Class instantiation (set the pin of the drivetrain)
    Drivetrain(int);

    // Proportional forwards/backwards w/ setting speed
    void move(int, int);

};

#endif
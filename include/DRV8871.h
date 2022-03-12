#ifndef DRV8871_H
#define DRV8871_H

class DRV8871{

    private:
    
    // Pin digital direction output pins for linear actuators
    // Default set to 1 upon constructor (Set motors to neutral)
        int lin_left1_dir = 1,
            lin_left2_dir = 1,
            lin_right1_dir = 1,
            lin_right2_dir = 1;

    // Pin locations for Actuators
        int lin_left1_pin,
            lin_left2_pin,
            lin_right1_pin,
            lin_right2_pin;

    // Breakout board methods 
        void forward();
        void backward();
        void stop();

    // Sets the output direction
        void set_output(int, int, int, int);

    public:

    // Movement methods (Assume speed will be constant)
    // FUTURE TODO (Adjust speed if needed for Lin. Act)
        void DRV8871_move(int);
        void DRV8871_stop();

    // Set linear actuator pins
        void set_linear_pins(int, int, int, int);

};

#endif
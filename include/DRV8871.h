#ifndef DRV8871_H
#define DRV8871_H

class DRV8871{

    private:
    
    // Pin digital direction output pins for linear actuators
    // Default set to 1 upon constructor (Set motors to neutral)
        int lin1_dir = 1,
            lin2_dir = 1;

    // Pin locations for Actuators
        int lin1_pin,
            lin2_pin;

    // Breakout board methods 
        void forward();
        void backward();
        void stop();

    // Sets the output direction
        void set_output(int, int);

    public:

    // Constructor (Initializes pins)
        DRV8871(int=0, int=0);

    // Movement methods (Assume speed will be constant)
    // FUTURE TODO (Adjust speed if needed for Lin. Act)
        void DRV8871_move(int);
        void DRV8871_stop();

    // Set linear actuator pins
        void set_breakout_pins(int, int);

};

#endif
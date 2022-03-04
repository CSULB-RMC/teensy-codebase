#include <Arduino.h>

#define DRIVETRAIN_PIN 2
#define PWM_FREQ 100

#define FORWARD_MIN   39
#define FORWARD_MAX   51
#define NEUTRAL       38
#define BACKWARD_MIN  25
#define BACKWARD_MAX  37

// Variable to write to Teensy
int pulse_duration = 0;

// This is drivetrain proportional forward
void drivetrain_forward(int speed){

  // Map out the value of the pulse
  pulse_duration = map(speed, 0, 100, FORWARD_MIN, FORWARD_MAX);
  
  // Set the duty cycle
  analogWrite(DRIVETRAIN_PIN, pulse_duration);

}

// This is drivetrain proportional backwards
void drivetrain_backwards(int speed){

  // Map out the value of the pulse
  pulse_duration = map(speed, 0, 100, BACKWARD_MIN, BACKWARD_MAX);
  
  // Set the duty cycle
  analogWrite(DRIVETRAIN_PIN, pulse_duration);
}

// This is drivetrain with a setting for direction and speed
// direction = 0 (Back), direction = 1 (forward)
void drivetrain_move(int direction, int speed){

  // Map out the value of the pulse
  if (direction){
    pulse_duration = map(speed, 0, 100, FORWARD_MIN, FORWARD_MAX);
  }
  else{
    pulse_duration = map(speed, 0, 100, BACKWARD_MIN, BACKWARD_MAX);
  }
  // Set the duty cycle
  analogWrite(DRIVETRAIN_PIN, pulse_duration);
}

// Drivetrain Neutral mode
void drivetrain_neutral(){

  analogWrite(DRIVETRAIN_PIN, NEUTRAL);
}

void setup() {
  
  // Set the pins to OUTPUT
    pinMode(DRIVETRAIN_PIN, OUTPUT);

  // Set DRIVETRAIN_PIN to the PWM frequency
    analogWriteFrequency(DRIVETRAIN_PIN, PWM_FREQ);

  // Loop through speeds for backwards and forwards
  for(int dir = 0; dir < 2; dir++){
    for(int spd = 0; spd <= 100; spd++){
      
      // Set the speed and direction 
      drivetrain_move(dir, spd);
      
      // Wait for 500ms 
      delay(500);
    }
  }
}

void loop() {    

}
#include <Arduino.h>

#define LED_60Hz 2
#define LED_Base 1

int pwm_signal = 0;

void setup() {
  
  // Set the pins to OUTPUT
    pinMode(LED_60Hz, OUTPUT);
    pinMode(LED_Base, OUTPUT);

  // Set pin2 LED_60Hz to 60 Hz frequency
    analogWriteFrequency(LED_60Hz, 60);
}

void loop() {    
  // Will start with a duty cycle of 0 and ramp up to 100
    for(int i = 0; i <= 100; i++){

        // Maps the corresponding signal to the resolution of the pin
        pwm_signal = map(i, 0, 100, 0, 255);

        // Output the translated duty cycle
        analogWrite(LED_60Hz, pwm_signal);
        analogWrite(LED_Base, pwm_signal);

        // Wait for 1/2 second
        delay(500);
    }
}
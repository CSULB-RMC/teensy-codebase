#include <Arduino.h>

int pwm_signal = 0;

void setup() {
  // Map out the signals
  for(int i = 0; i <= 100; i++){

      pwm_signal = map(i, 0, 100, 0, 255);
      Serial.println(pwm_signal);
  }
}

void loop() {    

}
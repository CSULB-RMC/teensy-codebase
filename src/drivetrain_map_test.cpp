#include <Arduino.h>

int pwm_signal = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {    

  // Map out the signals
  for(int i = 500; i <= 2500; i += 100){

      // So essentially given that a 100hz frequency has a period of 10,000 micro-Seconds
      // To reach the minimum allowable range for the pulse duration (500 <= p <= 2500)
      // Since 10,000 micro-Seconds divided by 256 divisions (resolution of PWM signal) 
      // equates to approx 39 divisions, You can find what division the 500 micro-second duration
      // is at by dividing 500 with 39 divisions. Hence, at the 13th division is a valid input
      // to drive the spark max
      pwm_signal = map(i, 500, 2500, 13, 255);
      Serial.println(pwm_signal);
  }

}
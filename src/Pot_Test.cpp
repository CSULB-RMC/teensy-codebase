#include <Arduino.h>

#define POT_PORT 14
#define ONBOARD_LED 13

int percent_out(int);
int metric_out(int);

void setup(){

    // Set pin 14 to inpit
    pinMode(POT_PORT, INPUT);
    pinMode(ONBOARD_LED, OUTPUT);
    Serial.begin(9600);
}

int pot_value = 0,
    prev_pot_value = 0,
    percent_val = 0,
    metric_val = 0;

void loop(){

    // Read the potentiometer value
    pot_value = analogRead(POT_PORT);

    // Convert the potentiometer value to % and metric form
    percent_val = percent_out(pot_value);
    metric_val = metric_out(pot_value);

    // Output to Serial and LED
    analogWrite(ONBOARD_LED, pot_value/4);

    // Only output value when there is a change
    if(prev_pot_value != pot_value){
        Serial.print(pot_value);
        Serial.print('\n');
        Serial.print(percent_val);
        Serial.print('\n');
        Serial.print(metric_val);
        Serial.print('\n');
    }
    
    // Set the previous state
    prev_pot_value = pot_value;

    // Wait 100 ms before reading next value
    delay(100);
}

int percent_out(int pot_val){

    // Map the pot value to the corresponding percentage
    return map(pot_val, 0, 1023, 0, 100);
}

int metric_out(int pot_val){

    // map the pot value to a metric value (assume cm)
    return map(pot_val, 0, 1023, 0, 5);

}
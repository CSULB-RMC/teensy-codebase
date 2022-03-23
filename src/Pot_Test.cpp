#include <Arduino.h>

#define POT_PORT 14

int percent_out(int);
int metric_out(int);

void setup(){

    // Set pin 14 to inpit
    pinMode(POT_PORT, INPUT);
    Serial.begin(9600);
}

int pot_value = 0, 
    percent_val = 0,
    metric_val = 0;

void loop(){

    // Read the potentiometer value
    pot_value = analogRead(POT_PORT);

    // Convert the potentiometer value to % and metric form
    percent_val = percent_out(pot_value);
    metric_val = metric_out(pot_value);

    // Output
    Serial.print(pot_value);
    Serial.print("");
    Serial.print(percent_val);
    Serial.print("");
    Serial.print(metric_val);
    Serial.print("");

    // Wait 1 second before reading next value
    delay(1000);
}

int percent_out(int pot_val){

    // Map the pot value to the corresponding percentage
    return map(pot_val, 0, 1023, 0, 100);
}

int metric_out(int pot_val){

    // map the pot value to a metric value (assume cm)
    return map(pot_val, 0, 1023, 0, 5);

}
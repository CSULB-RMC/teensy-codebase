#include "main.h"


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);  

  #ifdef SD_DEBUG
  SD_logger_init();
  #else
  Serial3.begin(9600);
  #endif
  

  printFuncln("Began serial connection");
  
  #ifdef USING_MICROROS
  while(setupROS() < 0) {
    printFuncln("ros setup failed... restarting init process in 2 seconds.");
    delay(2000);
  }
  
  printFuncln("Microros init successful!");
  #endif

  Drivetrain dt(0, 1); //TODO: replace these with the actual pins, this is just a test

}

void loop() {
  delay(100);
  #ifdef USING_MICROROS
  RCSOFTCHECK(rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100)));
  #else
  // ???
  #endif
}


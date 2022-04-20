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

  Drivetrain dt(8, 9); //TODO: replace these with the actual pins, this is just a test
  //BucketLadder bl(2, 3, 4, 5, 6, 7, 8); //TODO: replace these with the actual pins
  //RegCon rc(9, 10, 11, 12, 13, 14); //TODO: replace with actual pins

  /*
  if (dt.getError())
    printFuncln("Error trying to create Drivetrain. Will be non-functional/crash.");
  if (bl.getError())
    printFuncln("Error trying to create Bucketladder. Will be non-functional/crash.");  
  */
  #endif

  #ifndef USING_MICROROS

  //ADD NON MICROROS TEST SETUP CODE HERE

  #endif

}

void loop() {
  delay(100);
  #ifdef USING_MICROROS
  RCSOFTCHECK(rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100)));
  #else
  // ???
  #endif
}


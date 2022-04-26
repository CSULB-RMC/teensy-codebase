#include "main.h"

#ifdef USING_MICROROS //variables used for setting up microros
Drivetrain * dt;

rcl_subscription_t dt_left_sub;
rcl_subscription_t dt_right_sub;

std_msgs__msg__Int8 dt_msg;
#endif

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

  //lets make the objects
  dt = new Drivetrain(8, 9);
  //BucketLadder bl(2, 3, 4, 5, 6, 7, 8); //TODO: replace these with the actual pins
  //RegCon rc(9, 10, 11, 12, 13, 14); //TODO: replace with actual pins

  //Drivetrain Micro-ROS stuff

  RCSOFTCHECK(rclc_subscription_init_default(&dt_left_sub, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int8), "dt_left"));
  RCSOFTCHECK(rclc_subscription_init_default(&dt_right_sub, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int8), "dt_right"));

  RCSOFTCHECK(rclc_executor_add_subscription_with_context(&executor, &dt_left_sub, &dt_msg, &(Drivetrain::dt_left_callback), dt, ON_NEW_DATA)); //insane person code
  RCSOFTCHECK(rclc_executor_add_subscription_with_context(&executor, &dt_right_sub, &dt_msg, &(Drivetrain::dt_right_callback), dt, ON_NEW_DATA));

  //Bucketladder Micro-ROS stuff

  //Regcon Micro-ROS stuff
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


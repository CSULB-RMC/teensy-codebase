#include "main.h"

#ifdef USING_MICROROS //variables used for setting up microros
Drivetrain * dt;
BucketLadder * bl;
RegCon * rc;

rcl_subscription_t dt_left_sub;
rcl_subscription_t dt_right_sub;
rcl_subscription_t rc_sub;

std_msgs__msg__Int8 dt_msg;
std_msgs__msg__Int8 rc_msg;

rcl_subscription_t bl_lift_sub;
rcl_subscription_t bl_tele_sub;
rcl_subscription_t bl_dig_sub;

std_msgs__msg__Int8 bl_lift_msg;
std_msgs__msg__Int8 bl_tele_msg;
std_msgs__msg__Int8 bl_dig_msg;

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
  bl = new BucketLadder(6, 7, 2, 3, 12, 24, 25);
  rc = new RegCon(4, 5, 0, 1, 28, 29);

  //Drivetrain Micro-ROS stuff

  RCSOFTCHECK(rclc_subscription_init_default(&dt_left_sub, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int8), "dt_left"));
  RCSOFTCHECK(rclc_subscription_init_default(&dt_right_sub, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int8), "dt_right"));

  RCSOFTCHECK(rclc_executor_add_subscription_with_context(&executor, &dt_left_sub, &dt_msg, &(Drivetrain::dt_left_callback), dt, ON_NEW_DATA)); //insane person code
  RCSOFTCHECK(rclc_executor_add_subscription_with_context(&executor, &dt_right_sub, &dt_msg, &(Drivetrain::dt_right_callback), dt, ON_NEW_DATA));

  //Bucketladder Micro-ROS stuff
  RCSOFTCHECK(rclc_subscription_init_default(&bl_lift_sub, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int8), "bucketladder_lifter_control"));
  RCSOFTCHECK(rclc_subscription_init_default(&bl_tele_sub, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int8), "bucketladder_telescope_control"));
  RCSOFTCHECK(rclc_subscription_init_default(&bl_dig_sub, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int8), "bucketladder_digger_control"));

  RCSOFTCHECK(rclc_executor_add_subscription_with_context(&executor, &bl_lift_sub, &bl_lift_msg, &(BucketLadder::bl_lift_callback), bl, ON_NEW_DATA));
  RCSOFTCHECK(rclc_executor_add_subscription_with_context(&executor, &bl_tele_sub, &bl_tele_msg, &(BucketLadder::bl_tele_callback), bl, ON_NEW_DATA));
  RCSOFTCHECK(rclc_executor_add_subscription_with_context(&executor, &bl_dig_sub, &bl_dig_msg, &(BucketLadder::bl_dig_callback), bl, ON_NEW_DATA));

  //Regcon Micro-ROS stuff
  //RCSOFTCHECK(rclc_subscription_init_default(&rc_sub, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int8), "dumper_control"));

  //RCSOFTCHECK(rclc_executor_add_subscription_with_context(&executor, &rc_sub, &rc_msg, &(RegCon::rc_callback), rc, ON_NEW_DATA));

  #endif

  #ifndef USING_MICROROS

  //ADD NON MICROROS TEST SETUP CODE HERE

  #endif

}

void loop() {
  
  // Wait before reading new values
  delay(MICRO_ROS_READ_PERIOD);
  #ifdef USING_MICROROS
  RCSOFTCHECK(rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100)));
  #else
  // ???
  #endif
}


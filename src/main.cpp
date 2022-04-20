#include "main.h"

#include <micro_ros_arduino.h>

#include <stdio.h>
#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <std_msgs/msg/int8.h>
#include <std_msgs/msg/empty.h>

#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){printFunc(#fn " Error Code: "); printFuncln(temp_rc); return -1;}}
#define RCSOFTCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){printFunc(#fn " Error Code: "); printFuncln(temp_rc);}}
#define RCCLASSCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){printFunc(#fn " Error Code: "); printFuncln(temp_rc); microros_error = true;}}


Drivetrain* dt;
rcl_node_t node;
rclc_executor_t executor;
rclc_support_t support;
rcl_allocator_t allocator;

void test_LED_go(const void *msgin) {
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}

void dt_left_callback(const void *msgin) {
    const std_msgs__msg__Int8 * speed = (const std_msgs__msg__Int8 *)msgin;

    dt->move_left(speed->data);
}

void dt_right_callback(const void *msgin) {
    const std_msgs__msg__Int8 * speed = (const std_msgs__msg__Int8 *)msgin;

    dt->move_right(speed->data);
}

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

  dt = new Drivetrain(8, 9); //TODO: replace these with the actual pins, this is just a test
  //BucketLadder bl(2, 3, 4, 5, 6, 7, 8); //TODO: replace these with the actual pins
  //RegCon rc(9, 10, 11, 12, 13, 14); //TODO: replace with actual pins
  rcl_subscription_t dt_left_sub;
  rcl_subscription_t dt_right_sub;

  std_msgs__msg__Int8 msg;

  RCSOFTCHECK(rclc_subscription_init_default(&dt_left_sub, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int8), "dt_left"));
  RCSOFTCHECK(rclc_subscription_init_default(&dt_right_sub, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int8), "dt_right"));

  RCSOFTCHECK(rclc_executor_add_subscription(&executor, &dt_left_sub, &msg, &dt_left_callback, ON_NEW_DATA)); //insane person code
  RCSOFTCHECK(rclc_executor_add_subscription(&executor, &dt_right_sub, &msg, &dt_right_callback, ON_NEW_DATA));
  /*
  if (dt.getError())
    printFuncln("Error trying to create Drivetrain. Will be non-functional/crash.");
  if (bl.getError())
    printFuncln("Error trying to create Bucketladder. Will be non-functional/crash.");  
  */
  #endif

  #ifndef USING_MICROROS

  printFuncln("Starting microROS");
  set_microros_transports();

  delay(2000);

  allocator = rcl_get_default_allocator();
  printFuncln("Got default allocator");

  //create init_options
  RCSOFTCHECK(rclc_support_init(&support, 0, NULL, &allocator));
  printFuncln("rclc_support_init Success.");


  // create node
  RCSOFTCHECK(rclc_node_init_default(&node, "micro_ros_arduino_node", "", &support));
  printFuncln("rclc_node_init_default Success.");

  // create executor
  RCSOFTCHECK(rclc_executor_init(&executor, &support.context, 1, &allocator));
  printFuncln("rclc_executor_init Success.");

  pinMode(LED_BUILTIN, OUTPUT);
  dt = new Drivetrain(8, 9); //TODO: replace these with the actual pins, this is just a test
  //BucketLadder bl(2, 3, 4, 5, 6, 7, 8); //TODO: replace these with the actual pins
  //RegCon rc(9, 10, 11, 12, 13, 14); //TODO: replace with actual pins
  rcl_subscription_t dt_left_sub;
  rcl_subscription_t dt_right_sub;
  rcl_subscription_t testLED_sub;

  std_msgs__msg__Int8 msg;

  RCSOFTCHECK(rclc_subscription_init_default(&dt_left_sub, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int8), "dt_left"));
  RCSOFTCHECK(rclc_subscription_init_default(&dt_right_sub, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int8), "dt_right"));
  RCSOFTCHECK(rclc_subscription_init_default(&testLED_sub, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Empty), "test_led"));

  RCSOFTCHECK(rclc_executor_add_subscription(&executor, &dt_left_sub, &msg, &dt_left_callback, ON_NEW_DATA)); //insane person code
  RCSOFTCHECK(rclc_executor_add_subscription(&executor, &dt_right_sub, &msg, &dt_right_callback, ON_NEW_DATA));
  RCSOFTCHECK(rclc_executor_add_subscription(&executor, &testLED_sub, NULL, &test_LED_go, ON_NEW_DATA));
  

  //ADD NON MICROROS TEST SETUP CODE HERE

  #endif

}

void loop() {
  delay(100);
  
  #ifdef USING_MICROROS
  RCSOFTCHECK(rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100)));
  #else
  RCSOFTCHECK(rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100)));
  #endif
}


#include "microros_setup.h"
#include "config.h"

rcl_node_t node;
rclc_executor_t executor;
rclc_support_t support;
rcl_allocator_t allocator;

int setupROS() {
  
  printFuncln("Starting microROS");
  Serial.begin(115200);
  set_microros_serial_transports(Serial);

  delay(2000);

  allocator = rcl_get_default_allocator();
  printFuncln("Got default allocator");

  //create init_options
  RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));
  printFuncln("rclc_support_init Success.");


  // create node
  RCCHECK(rclc_node_init_default(&node, "micro_ros_arduino_node", "", &support));
  printFuncln("rclc_node_init_default Success.");

  // create executor
  RCCHECK(rclc_executor_init(&executor, &support.context, 2, &allocator));
  printFuncln("rclc_executor_init Success.");

  return 0;
}

int initExecutor() {
  RCCHECK(rclc_executor_init(&executor, &support.context, 1, &allocator));

  return 0;
}
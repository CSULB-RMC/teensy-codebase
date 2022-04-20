#include "microros_setup.h"
#include "config.h"



int setupROS() {
  rcl_node_t node;
rclc_executor_t executor;
rclc_support_t support;
rcl_allocator_t allocator;
  
  printFuncln("Starting microROS");
  set_microros_transports();

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
  RCCHECK(rclc_executor_init(&executor, &support.context, 1, &allocator));
  printFuncln("rclc_executor_init Success.");

  return 0;
}
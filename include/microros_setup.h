#ifndef LBL_MICROROS_H
#define LBL_MICROROS_H
//file just used to include all the important microros headers

#include <micro_ros_arduino.h>

#include <stdio.h>
#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){printFunc(#fn " Error Code: "); printFuncln(temp_rc); return -1;}}
#define RCSOFTCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){printFunc(#fn " Error Code: "); printFuncln(temp_rc);}}
#define RCCLASSCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){printFunc(#fn " Error Code: "); printFuncln(temp_rc); microros_error = true;}}

//extern rcl_node_t node;
//extern rclc_executor_t executor;

int setupROS();

#endif // LBL_MICROROS_H
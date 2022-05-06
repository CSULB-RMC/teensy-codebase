#ifndef LBL_CONFIG_H
#define LBL_CONFIG_H

#include "SD_logger.h"

//CONFIG OPTIONS: COMMENT TO DISABLE, UNCOMMENT TO ENABLE
#define SD_DEBUG //log errors to SD card. Disabled logs errors to Serial3
#define ENABLE_LOG_LED
#define USING_MICROROS //compile the various classes with support for microros (will fail if microros is not an included library)
#define MICROROS_MAX_SUBSCRIBERS    5

#ifdef SD_DEBUG
#define printFunc(text)       SD_log(text)
#define printFuncln(text)     SD_logln(text)
#else
#define printFunc       Serial3.print
#define printFuncln     Serial3.println
#endif

// Motor speed limit variable 
#define MAX_MOTOR_PERCENT 0.4

// Read rate delay variable
#define MICRO_ROS_READ_PERIOD 10

// Regolith Containment Min and Max Extension
// Note (UP = 60, Down = 104) during mechanical testing
#define REG_LIN_UP      60
#define REG_LIN_DOWN    104

// Regolith Containment Sifter
#define BAG_REG_SPEED_FORWARD 100
#define BAG_REG_SPEED_BACKWARD 80

// Bucketladder Min and Max extension
// Note need to do testing for Bucketladder linears
#define BUCK_LIN_UP     180
#define BUCK_LIN_DOWN   0

// Bucketladder BAG motor speed limiting variables

#define BAG_BUCK_SPEED_FORWARD 100
#define BAG_BUCK_SPEED_BACKWARD 80

#define CIM_WINCH_SPEED_FORWARD 100
#define CIM_WINCH_SPEED_BACKWARD 80

#endif // LBL_CONFIG_H
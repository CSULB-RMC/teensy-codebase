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

#endif // LBL_CONFIG_H
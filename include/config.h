#ifndef LBL_CONFIG_h
#define LBL_CONFIG_H

#include "SD_logger.h"

#define SD_DEBUG

#ifdef SD_DEBUG
#define printFunc(text)       SD_log(text)
#define printFuncln(text)     SD_logln(text)
#else
#define printFunc       Serial3.print
#define printFuncln     Serial3.println
#endif

#endif // LBL_CONFIG_H
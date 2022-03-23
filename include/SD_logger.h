#ifndef SD_LOGGER_H
#define SD_LOGGER_H

#include <Arduino.h>
#include <SD.h>

void SD_logger_init();

void SD_log(const char * msg);
void SD_log(int msg);

void SD_logln(const char * msg);
void SD_logln(int msg);

#endif // SD_LOGGER_H
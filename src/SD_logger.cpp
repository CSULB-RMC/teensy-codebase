#include "SD_logger.h"

File dataFile;

void SD_logger_init() {
    #ifdef ENABLE_LOG_LED
    pinMode(LED_BUILTIN, OUTPUT);
    #endif
    SD.begin(BUILTIN_SDCARD);
    SD.remove("datalog.txt");
}

void SD_log(const char* msg) {
    #ifdef ENABLE_LOG_LED
    digitalWrite(LED_BUILTIN, LOW);
    #endif
    dataFile = SD.open("datalog.txt", FILE_WRITE);
    dataFile.print(msg);
    dataFile.close();
    #ifdef ENABLE_LOG_LED
    digitalWrite(LED_BUILTIN, HIGH);
    #endif
}
void SD_log(int msg) {
    #ifdef ENABLE_LOG_LED
    digitalWrite(LED_BUILTIN, LOW);
    #endif
    dataFile = SD.open("datalog.txt", FILE_WRITE);
    dataFile.print(msg);
    dataFile.close();
    #ifdef ENABLE_LOG_LED
    digitalWrite(LED_BUILTIN, HIGH);
    #endif
}

void SD_logln(const char* msg) {
    #ifdef ENABLE_LOG_LED
    digitalWrite(LED_BUILTIN, LOW);
    #endif
    dataFile = SD.open("datalog.txt", FILE_WRITE);
    dataFile.println(msg);
    dataFile.close();
    #ifdef ENABLE_LOG_LED
    digitalWrite(LED_BUILTIN, HIGH);
    #endif
}
void SD_logln(int msg) {
    #ifdef ENABLE_LOG_LED
    digitalWrite(LED_BUILTIN, LOW);
    #endif
    dataFile = SD.open("datalog.txt", FILE_WRITE);
    dataFile.println(msg);
    dataFile.close();
    #ifdef ENABLE_LOG_LED
    digitalWrite(LED_BUILTIN, HIGH);
    #endif
}
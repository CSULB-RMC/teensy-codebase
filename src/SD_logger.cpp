#include "SD_logger.h"

File dataFile;

void SD_logger_init() {
    SD.begin(BUILTIN_SDCARD);
    SD.remove("datalog.txt");
}

void SD_log(const char* msg) {
    digitalWrite(LED_BUILTIN, LOW);
    dataFile = SD.open("datalog.txt", FILE_WRITE);
    dataFile.print(msg);
    dataFile.close();
    digitalWrite(LED_BUILTIN, HIGH);
}
void SD_log(int msg) {
    digitalWrite(LED_BUILTIN, LOW);
    dataFile = SD.open("datalog.txt", FILE_WRITE);
    dataFile.print(msg);
    dataFile.close();
    digitalWrite(LED_BUILTIN, HIGH);
}

void SD_logln(const char* msg) {
    digitalWrite(LED_BUILTIN, LOW);
    dataFile = SD.open("datalog.txt", FILE_WRITE);
    dataFile.println(msg);
    dataFile.close();
    digitalWrite(LED_BUILTIN, HIGH);
}
void SD_logln(int msg) {
    digitalWrite(LED_BUILTIN, LOW);
    dataFile = SD.open("datalog.txt", FILE_WRITE);
    dataFile.println(msg);
    dataFile.close();
    digitalWrite(LED_BUILTIN, HIGH);
}
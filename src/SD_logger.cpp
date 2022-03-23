#include "SD_logger.h"

File dataFile;

void SD_logger_init() {
    SD.begin(BUILTIN_SDCARD);
    SD.remove("datalog.txt");
}

void SD_log(const char* msg) {
    dataFile = SD.open("datalog.txt", FILE_WRITE);
    dataFile.print(msg);
    dataFile.close();
}
void SD_log(int msg) {
    dataFile = SD.open("datalog.txt", FILE_WRITE);
    dataFile.print(msg);
    dataFile.close();
}

void SD_logln(const char* msg) {
    dataFile = SD.open("datalog.txt", FILE_WRITE);
    dataFile.println(msg);
    dataFile.close();
}
void SD_logln(int msg) {
    dataFile = SD.open("datalog.txt", FILE_WRITE);
    dataFile.println(msg);
    dataFile.close();
}
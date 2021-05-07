#include "fileLogger.h"

Logger& FileLogger::instance(){
    static FileLogger singleton;
    return singleton;
}
void FileLogger::log(string text){
    time_t now = time(nullptr);
    char buffer[100] = {};
    strftime(buffer, sizeof(buffer),"%d-%m-%Y %H:%M:%S", gmtime(&now));
    string time_ = string(buffer);
    cout << time_<< text <<endl;
}

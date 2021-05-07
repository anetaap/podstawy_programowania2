#include "databaseLogger.h"

Logger& DatabaseLogger::instance(){
    static DatabaseLogger singleton;
    return singleton;
}
void DatabaseLogger::log(string text){
    time_t now = time(nullptr);
    char buffer[100] = {};
    strftime(buffer, sizeof(buffer),"%d-%m-%Y %H:%M:%S", gmtime(&now));
    string time_ = string(buffer);
    cout << time_<<text<<endl;
}

#ifndef DATABASELOGGER_H
#define DATABASELOGGER_H
#include "logger.h"

class DatabaseLogger:public Logger{
    DatabaseLogger() = default;
    ~DatabaseLogger() = default;
public:
    void log(string text) override;
    static Logger& instance();
};

#endif //DATABASELOGGER_H

#ifndef FILELOGGER_H
#define FILELOGGER_H
#include "logger.h"
#include <fstream>

class FileLogger:public Logger{
private:
    FileLogger() = default;
    ~FileLogger() = default;
    fstream plik;
public:
    static Logger& instance();
    void log(string text) override;
};

#endif //LABORATORIUM9_FILELOGGER_H

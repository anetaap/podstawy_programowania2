#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H
#include "logger.h"
using namespace std;
class ConsoleLogger : public Logger{
private:
    ConsoleLogger() = default;
    ~ConsoleLogger() = default;
public:
    static Logger& instance();
    void log(string text) override;
};

#endif //CONSOLELOGGER_H

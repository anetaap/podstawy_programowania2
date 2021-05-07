#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Logger{
    Logger() = default;
public:
    static Logger& instance();
    //static void registerInstance(string txt, Logger* instance);
    virtual void log(string text) = 0;
};

#endif // LOGGER_H

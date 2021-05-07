#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;


int main(int argc, char* argv[])
{
    Logger::registerInstance("ConsoleLogger", ConsoleLogger::instance());
    // ... i inne loggery
    if (argc > 1)
    {
        Logger::setInstanceByName(argv[1]);
    }
    Logger::instance().log("Meldujemy wykonanie zadania!");

}

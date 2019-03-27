#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <ctime>
#include "fooditem.h"

class Logger
{
public:

    Logger();
    Logger(const std::string& logFile);

    void addItem(FoodItem* food, int g);
    std::string summary(const std::string& date) const;
    std::string summary() const;

private:

    std::string file_;
    int targetCals_;

    std::string getDate() const;
    void readTarget();
    std::vector<std::string> parseLine(const std::string& csvLine) const;

};

#endif // LOGGER_H

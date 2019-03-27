#include "logger.h"
#include <fstream>
#include <iostream>

Logger::Logger()
{

}


Logger::Logger(const std::string &logFile) : file_(logFile)
{
    readTarget();
    std::cout << getDate() << std::endl;
}

void Logger::addItem(FoodItem *food, int g)
{
    std::ofstream file(file_, std::ios::app);
    if(!file.is_open())
    {
        file.close();
        return;
    }
    else
    {
        file << getDate() << ";" << food->name() << ";" << food->cal(g)
             << ";" << food->prot(g) << ";" << food->fat(g) << ";" << food->carb(g) << std::endl;
        file.close();
    }
}

std::string Logger::summary(const std::string &date) const
{
    std::ifstream file(file_);
    if(!file.is_open()) return "";

    int cal = 0; int prot = 0;
    int fat = 0; int carb = 0;

    std::string line;
    while(getline(file, line))
    {
        auto vec = parseLine(line);
        if(vec.size() == 6 && vec[0] == date)
        {
            cal += std::stoi(vec[2]);
            prot += std::stoi(vec[3]);
            fat += std::stoi(vec[4]);
            carb += std::stoi(vec[5]);
        }
    }

    std::string summary = "Calories for this date: " + std::to_string(cal) + '\n'
            + "Protein: " + std::to_string(prot) + '\n'
            + "Fat: " + std::to_string(fat) + '\n'
            + "Carb: " + std::to_string(carb);

    file.close();
    return  summary;
}

std::string Logger::summary() const
{
    return summary(getDate());
}


std::string Logger::getDate() const
{
    time_t now = time(nullptr);
    tm* ltm = localtime(&now);

    std::string date;
    date += std::to_string( 1900 + ltm->tm_year );
    date += std::to_string( ltm->tm_mon + 1 );
    date += std::to_string( ltm->tm_mday );

    return  date;

}

void Logger::readTarget()
{
    std::fstream file(file_);
    std::string line;
    if(!file.is_open())
    {
        file.close();
        return;
    }
    else
    {
        getline(file, line);
        file.close();
    }
    try
    {
        targetCals_ = std::stoi(line);
        std::cout << targetCals_ << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

}

std::vector<std::string> Logger::parseLine(const std::string &csvLine) const
{
    std::vector<std::string> items;
    std::string item;

    for(char c : csvLine)
    {
        if(c == ';')
        {
            items.push_back(item);
            item = "";
        }
        else
        {
            item += c;
        }
    }
    items.push_back(item);
    return  items;
}

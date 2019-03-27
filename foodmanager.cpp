#include "foodmanager.h"
#include <fstream>
#include <iostream>

FoodManager::FoodManager(const std::string& path) : filepath_(path)
{
    readData();
}

bool FoodManager::readData()
{
    std::ifstream file(filepath_);
    if(!file.is_open())
    {
        std::cout << "Failed to open file" << std::endl;
        file.close();
        return false;
    }

    std::string line;
    int lineNumber = 0;
    while(getline(file, line))
    {
        ++lineNumber;
        if(line.length() > 0 && line[0] != comment_)
        {
            try
            {
                foodItems_.push_back(std::make_unique<FoodItem>(line));
            }
            catch (std::exception& e)
            {
                std::cerr << e.what() << " in line " << lineNumber << std::endl;
            }
        }
    }

    file.close();
    return true;
}


bool FoodManager::addItem(const std::string& csvLine)
{
    std::ofstream file;
    file.open(filepath_, std::ios::app);

    if(file.is_open())
    {
        file << csvLine << std::endl;
    }
    else
    {
        file.close();
        return false;
    }
    try
    {
        foodItems_.push_back(std::make_unique<FoodItem>(csvLine));
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    file.close();
    return  true;
}

FoodItem *FoodManager::getFood(const std::string &name)
{
    for(auto& food : foodItems_)
    {
        if(food->name() == name)
        {
            return  food.get();
        }
    }
    return  nullptr;
}

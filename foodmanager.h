#ifndef DATAMANAGER_H
#define DATAMANAGER_H
#include <string>
#include <vector>
#include <memory>
#include "fooditem.h"


class FoodManager
{
public:
    FoodManager();
    FoodManager(const std::string& path);
    bool addItem(const std::string& csvLine);

    FoodItem *getFood(const std::string &name);

private:
    std::string filepath_;
    std::vector<std::unique_ptr<FoodItem>> foodItems_;

    const char comment_ = '#';
    bool readData();

};

#endif // DATAMANAGER_H

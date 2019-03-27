#include "fooditem.h"
#include <stdexcept>


FoodItem::FoodItem()
{


}

FoodItem::FoodItem(const std::string &csvLine)
{
    std::vector<std::string> csvItems = csvParser(csvLine);
    if(csvItems.size() == 5)
    {
        name_    =  csvItems[0];
        cal100g_ =  std::stoi(csvItems[1]);
        prot_    =  std::stoi(csvItems[2]);
        carb_    =  std::stoi(csvItems[3]);
        fat_     =  std::stoi(csvItems[4]);
    }
    else
    {
        throw std::invalid_argument("Faulty csv line");
    }

}

std::string FoodItem::name() const
{
    return  name_;
}

int FoodItem::prot(int g) const
{
    return prot_*g/100;
}

int FoodItem::carb(int g) const
{
    return carb_*g/100;
}

int FoodItem::fat(int g) const
{
    return fat_*g/100;
}


std::vector<std::string> FoodItem::csvParser(const std::string& csvLine)
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

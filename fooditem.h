#ifndef FOODITEM_H
#define FOODITEM_H
#include <string>
#include <vector>


class FoodItem
{
public:
    FoodItem();
    FoodItem(const std::string& csvLine);

    std::string name() const;
    int         prot(int g) const;
    int         carb(int g) const;
    int         fat (int g) const;

private:
    std::string name_;
    int         cal100g_;
    int         prot_;
    int         carb_;
    int         fat_;


    std::vector<std::string> csvParser(const std::string &csvLine);

};

#endif // FOODITEM_H

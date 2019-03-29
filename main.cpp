#include <iostream>
#include "foodmanager.h"
#include "logger.h"

int main(int argc, char** args)
{
    FoodManager f("foods.txt");
    Logger l(".log");


    if(argc == 1 )
    {
        std::cout << l.summary();
        return 0;
    }
    std::string command = args[1];

    if ( command == "add" )
    {
        std::string food = args[2];
        int g = std::stoi(args[3]);
        l.addItem(f.getFood(food), g);
        std::cout << "added item " << food << g << std::endl;
    }
    if (command == "today")
    {

    }

    return 0;
}

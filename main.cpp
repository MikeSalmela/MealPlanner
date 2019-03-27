#include <iostream>
#include "foodmanager.h"
#include "logger.h"

int main()
{
    FoodManager f("foods.txt");
    Logger l("test2.txt");
    l.addItem(f.getFood("pasta"), 300);
    l.addItem(f.getFood("groundbeef20"), 400);
    l.addItem(f.getFood("egg"), 200);
    l.addItem(f.getFood("milk"), 1000);
    l.addItem(f.getFood("ryebread"), 50);
    l.addItem(f.getFood("ketchup"), 100);
    std::cout << l.summary() << std::endl;

    return 0;
}

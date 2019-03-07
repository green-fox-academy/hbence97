//
// Created by hegye on 2019. 02. 14..
//

#include "restaurant.h"

Restaurant::Restaurant(std::string name, int foundedIn)
{
    _name = name;
    _foundedIn = foundedIn;
}

void Restaurant::guestsArrived()
{
    for (int i = 0; i <_employees.size() ; ++i) {
        _employees[i]->work();
    }
}

void Restaurant::hire(Employees &employee)
{
    _employees.push_back(&employee);
}
//
// Created by hegye on 2019. 02. 14..
//

#ifndef TRIAL_TRIAL_EXAM_RESTAURANT_H
#define TRIAL_TRIAL_EXAM_RESTAURANT_H

#include <iostream>
#include <vector>
#include "employees.h"

class Restaurant {
    std::string _name;
    int _foundedIn;
    std::vector<Employees *> _employees;
public:
    Restaurant(std::string name, int foundedIn);
    void guestsArrived();
    void hire(Employees &employee);
};


#endif //TRIAL_TRIAL_EXAM_RESTAURANT_H

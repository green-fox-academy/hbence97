//
// Created by hegye on 2019. 02. 14..
//

#ifndef TRIAL_TRIAL_EXAM_EMPLOYEES_H
#define TRIAL_TRIAL_EXAM_EMPLOYEES_H

#include <iostream>

class Employees {
protected:
    std::string _name;
    int _experience = 0;
public:
    Employees (int experience = 0);
    virtual void work() = 0;
};


#endif //TRIAL_TRIAL_EXAM_EMPLOYEES_H

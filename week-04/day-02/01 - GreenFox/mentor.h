//
// Created by hegye on 2019. 02. 06..
//

#ifndef INC_01_GREENFOX_MENTOR_H
#define INC_01_GREENFOX_MENTOR_H

#include <iostream>
#include "person.h"

enum LEVEL{
    Junior,
    Intermediate,
    Senior
};

class Mentor : public Person{
    LEVEL level;
public:
    Mentor (std::string name, int age, GENDER gender, LEVEL level);
    Mentor();
    void getGoal() override;
    void introduce() override;
};

#endif //INC_01_GREENFOX_MENTOR_H

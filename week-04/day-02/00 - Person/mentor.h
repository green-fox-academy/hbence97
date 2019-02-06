//
// Created by hegye on 2019. 02. 05..
//

#ifndef INC_00_PERSON_MENTOR_H
#define INC_00_PERSON_MENTOR_H

#include <iostream>
#include "person.h"
enum LEVEL{
    Junior,
    Intermediate,
    Senior
};

class mentor : public Person{
    LEVEL level;
public:
    mentor (std::string name, int age, GENDER gender, LEVEL level);
    mentor();
    void getGoal() override;
    void introduce() override;
};


#endif //INC_00_PERSON_MENTOR_H

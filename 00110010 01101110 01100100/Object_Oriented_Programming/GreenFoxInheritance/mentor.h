//
// Created by hegye on 2019. 07. 03..
//

#ifndef GREENFOXINHERITANCE_MENTOR_H
#define GREENFOXINHERITANCE_MENTOR_H

#include "person.h"

enum level{
    JUNIOR,
    INTERMEDIATE,
    SENIOR
};

class Mentor : public Person{
    enum level _level;
public:
    void getGoal() override;
    void introduce() override;

    Mentor(std::string name, int age, gender gender, level level);
    Mentor();
};

#endif //GREENFOXINHERITANCE_MENTOR_H

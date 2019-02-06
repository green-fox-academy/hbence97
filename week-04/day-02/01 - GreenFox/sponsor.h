//
// Created by hegye on 2019. 02. 06..
//

#ifndef INC_01_GREENFOX_SPONSOR_H
#define INC_01_GREENFOX_SPONSOR_H

#include "person.h"

class Sponsor : public Person {
    std::string company;
    int hiredStudents;
public:
    Sponsor(std::string name, int age, GENDER gender, std::string company);
    Sponsor();
    void hire();
    void introduce() override;
    void getGoal() override;
};

#endif //INC_01_GREENFOX_SPONSOR_H

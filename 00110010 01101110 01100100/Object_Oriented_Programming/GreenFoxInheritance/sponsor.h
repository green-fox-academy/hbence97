//
// Created by hegye on 2019. 07. 03..
//

#ifndef GREENFOXINHERITANCE_SPONSOR_H
#define GREENFOXINHERITANCE_SPONSOR_H

#include "person.h"

class Sponsor : public Person {
    std::string _company;
    int _hiredStudents;
public:
    void introduce() override;
    void getGoal() override;

    void hire();

    Sponsor(std::string name, int age, gender gender, std::string company);
    Sponsor();
};

#endif //GREENFOXINHERITANCE_SPONSOR_H

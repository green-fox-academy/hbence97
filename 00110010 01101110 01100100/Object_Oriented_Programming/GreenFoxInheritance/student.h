//
// Created by hegye on 2019. 07. 01..
//

#ifndef GREENFOXINHERITANCE_STUDENT_H
#define GREENFOXINHERITANCE_STUDENT_H

#include "person.h"

class Student : public Person{
    std::string _previousOrganization;
    int _skippedDays;
public:
    Student();
    Student(std::string name, int age, gender gender, std::string previousOrganization);
    int skipDays(int numberOfDays);

    void getGoal() override;
    void introduce() override;
};


#endif //GREENFOXINHERITANCE_STUDENT_H

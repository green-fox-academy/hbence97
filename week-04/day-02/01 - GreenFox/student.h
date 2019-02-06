//
// Created by hegye on 2019. 02. 06..
//

#ifndef INC_01_GREENFOX_STUDENT_H
#define INC_01_GREENFOX_STUDENT_H

#include <iostream>
#include "person.h"

class Student : public Person{

private:
    std::string previousOrganization;
    int skippedDays;
public:
    Student(std::string name, int age, GENDER gender, std::string previousOrganization, int skippedDays);
    Student();
    void getGoal() override;
    void introduce() override;
    void skipDays(int numberOfDays);


};

#endif //INC_01_GREENFOX_STUDENT_H

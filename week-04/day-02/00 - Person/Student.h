//
// Created by hegye on 2019. 02. 05..
//

#ifndef INC_00_PERSON_STUDENT_H
#define INC_00_PERSON_STUDENT_H

#include <iostream>
#include "person.h"

class student : public Person{

private:
    std::string previousOrganization;
    int skippedDays;
public:
    student(std::string name, int age, GENDER gender, std::string previousOrganization, int skippedDays);
    student();
    void getGoal() override;
    void introduce() override;
    void skipDays(int numberOfDays);


};


#endif //INC_00_PERSON_STUDENT_H

//
// Created by hegye on 2019. 02. 05..
//

#include "Student.h"
#include <iostream>

void student::introduce()
{
    std::cout << "Hi, I'm " << name << ", a " << age << " year old " << gender << " from " << previousOrganization << " who skipped " << skippedDays << " days from the course already." << std::endl;
}

void student::getGoal()
{
    std::cout << "My goal is: Be a junior software developer." << std::endl;
}

student::student(std::string _name, int _age, GENDER _gender,std::string _previousOrganization, int _skippedDays)
{
    name = _name;
    age = _age;
    gender = _gender;
    previousOrganization = _previousOrganization;
    skippedDays = _skippedDays;
}

student::student()
{
    name = "Jane Doe";
    age = 30;
    gender = GENDER::FEMALE;
    previousOrganization = "MZSG";
    skippedDays = 0;
}

void student::skipDays(int numberOfDays){

    skippedDays += numberOfDays;
}

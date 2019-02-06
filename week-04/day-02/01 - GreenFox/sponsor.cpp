//
// Created by hegye on 2019. 02. 06..
//

#include "sponsor.h"

Sponsor::Sponsor(std::string _name, int _age, GENDER _gender, std::string _company)
{
    name = _name;
    age = _age;
    gender = _gender;
    company = _company;
    hiredStudents = 0;
}

Sponsor::Sponsor()
{
    name = "Jane Doe";
    age = 30;
    gender = FEMALE;
    company = "Google";
    hiredStudents = 0;
}

void Sponsor::introduce()
{
    std::cout << "Hi, I'm " << name << " a " << age << " year old " << FEMALE << " who represents " << company << "and hired " << hiredStudents << " students so far." << std::endl;
}

void Sponsor::hire()
{
    hiredStudents += hiredStudents;
}

void Sponsor::getGoal()
{
    std::cout << "My goal is: Hire brilliant junior software developers." << std::endl;
}
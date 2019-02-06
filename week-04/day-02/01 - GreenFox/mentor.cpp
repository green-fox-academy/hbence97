//
// Created by hegye on 2019. 02. 06..
//

#include "Mentor.h"
#include <iostream>

Mentor::Mentor ( std::string _name, int _age, GENDER _gender, LEVEL _level)
{
    name = _name;
    age = _age;
    gender = _gender;
    level = _level;
}

Mentor::Mentor ()
{
    name = "Jane Doe";
    age = 30;
    gender = FEMALE;
    level = Intermediate;
}

void Mentor::getGoal()
{
    std::cout << "My goal is: Educate briliant junior software developers" << std::endl;
}

void Mentor::introduce()
{
    std::cout << "Hi, I'm " << name << " a " << age << " year old " << gender << level << "mentor." << std::endl;
}
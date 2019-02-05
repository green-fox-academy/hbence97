//
// Created by hegye on 2019. 02. 05..
//

#include "person.h"
#include <iostream>

void Person::introduce(){
    std::cout << "Hi,I'm " << name << ", a " << age << " year old " << gender << std::endl;
}

void Person::getGoal(){
    std::cout << "My goal is: Live for the moment!" << std::endl;
}

Person::Person(std::string _name, int _age, GENDER _gender) {
    name = _name;
    age = _age;
    gender = _gender;
}

Person::Person()
{
    name = "Jane Doe";
    age = 30;
    gender = GENDER::FEMALE;
}
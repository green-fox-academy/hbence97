//
// Created by hegye on 2019. 06. 30..
//

#include "person.h"

Person::Person(std::string name, int age, gender gender) {
    _name = name;
    _age = age;
    _gender = gender;
}

Person::Person() {
    _name = "Jane Doe";
    _age = 30;
    _gender = FEMALE;
}

void Person::introduce() {
    std::cout << "Hi, I'm " + _name +", a " + std::to_string(_age) + " year old " + std::to_string(_gender) << std::endl;
}

void Person::getGoal() {
    std::cout << "My goal is: Live for the moment" << std::endl;
}

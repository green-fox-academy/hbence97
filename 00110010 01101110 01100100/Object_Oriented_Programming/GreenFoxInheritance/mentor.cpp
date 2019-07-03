//
// Created by hegye on 2019. 07. 03..
//

#include "mentor.h"

void Mentor::getGoal() {
    std::cout << "My goal is: Educate brilliant junior software developers." << std::endl;
}

void Mentor::introduce() {
    std::cout << "Hi, I'm " + _name + " a " + std::to_string(_age) + " year old " + std::to_string(_gender) + " " + std::to_string(_level) + " mentor." << std::endl;
}

Mentor::Mentor(std::string name, int age, gender gender, level level) {
    _name = name;
    _age = age;
    _gender = gender;
    _level = level;
}

Mentor::Mentor() {
    _name = "Jane Doe";
    _age = 30;
    _gender = FEMALE;
    _level = INTERMEDIATE;
}


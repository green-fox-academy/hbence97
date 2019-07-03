//
// Created by hegye on 2019. 07. 03..
//

#include "sponsor.h"

void Sponsor::introduce() {
    std::cout << "Hi, I'm " + _name + " a " + std::to_string(_age) + " year old " + std::to_string(_gender) + " who represents " + _company +
    " and hired " + std::to_string(_hiredStudents) + " students so far." << std::endl;
}

void Sponsor::getGoal() {
    std::cout << "My goal is: Hire brilliant junior software developers." << std::endl;
}

void Sponsor::hire() {
    _hiredStudents += 1;
}

Sponsor::Sponsor(std::string name, int age, gender gender, std::string company) {
    _name = name;
    _age = age;
    _gender = gender;
    _company = company;
    _hiredStudents = 0;
}

Sponsor::Sponsor() {
    _name = "Jane Doe";
    _age = 30;
    _gender = FEMALE;
    _company = "Google";
    _hiredStudents = 0;
}

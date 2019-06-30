//
// Created by hegye on 2019. 07. 01..
//

#include "student.h"
#include "person.h"

Student::Student(std::string name, int age, gender gender, std::string previousOrganization) {
    _name = name;
    _age = age;
    _gender = gender;
    _previousOrganization = previousOrganization;
    _skippedDays = 0;
}

Student::Student() {
    _name = "Jane Doe";
    _age = 30;
    _gender = FEMALE;
    _previousOrganization = "The school of life";
    _skippedDays = 0;
}

void Student::getGoal() {
    std::cout << "My goal is: Be a junior software developer." << std::endl;
}

void Student::introduce() {
    std::cout << "Hi, I'm " + _name + " a " + std::to_string(_age) + " year old " + std::to_string(_gender) + " from "
    + _previousOrganization + " who skipped " + std::to_string(_skippedDays) + " days from the course." << std::endl;
}

int Student::skipDays(int numberOfDays) {
    _skippedDays += numberOfDays;
    return _skippedDays;
}


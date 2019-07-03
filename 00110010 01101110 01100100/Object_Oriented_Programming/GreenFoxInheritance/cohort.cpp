//
// Created by hegye on 2019. 07. 03..
//

#include "cohort.h"

void Cohort::addStudent(Student *student) {
    _students.push_back(student);
}

void Cohort::addMentor(Mentor *mentor) {
    _mentors.push_back(mentor);
}

void Cohort::info() {
    std::cout << "The " + _name + " cohort has " + std::to_string(_students.size()) + " students and " + std::to_string(_mentors.size()) +
    " mentors." << std::endl;
}

Cohort::Cohort(std::string name) {
    _name = name;
    _students.clear();
    _mentors.clear();
}



//
// Created by hegye on 2019. 02. 06..
//

#include "cohort.h"

void Cohort::addStudent(Student* student)
{
    students.push_back(student);
}
void Cohort::addMentor(Mentor* mentor)
{
     mentors.push_back(mentor);
}
void Cohort::info()
{
    std::cout << "The " << name << " cohort has " << students.size() << "students and " << mentors.size() << "mentors" << std::endl;
}

Cohort::Cohort(std::string _name)
{
    name = _name;
    students.empty();
    mentors.empty();
}
//
// Created by hegye on 2019. 07. 03..
//

#ifndef GREENFOXINHERITANCE_COHORT_H
#define GREENFOXINHERITANCE_COHORT_H

#include "student.h"
#include "mentor.h"
#include <iostream>
#include <vector>

class Cohort {
    std::string _name;
    std::vector<Student*> _students;
    std::vector<Mentor*> _mentors;
public:
    void addStudent(Student *student);
    void addMentor(Mentor *mentor);
    void info();

    Cohort(std::string name);

};


#endif //GREENFOXINHERITANCE_COHORT_H

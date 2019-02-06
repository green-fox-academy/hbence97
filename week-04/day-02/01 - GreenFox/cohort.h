//
// Created by hegye on 2019. 02. 06..
//

#ifndef INC_01_GREENFOX_COHORT_H
#define INC_01_GREENFOX_COHORT_H

#include <vector>
#include "mentor.h"
#include "student.h"

class Cohort {
    std::string name;
    std::vector <Student*> students;
    std::vector <Mentor*> mentors;
public:
    Cohort(std::string name);
    void addStudent(Student*);
    void addMentor(Mentor*);
    void info();
};


#endif //INC_01_GREENFOX_COHORT_H

//
// Created by hegye on 2019. 02. 25..
//

#ifndef RERETAKEEXAM3_QUEUE_H
#define RERETAKEEXAM3_QUEUE_H


#include <vector>
#include "patient.h"

class Queue {
public:
    void addPatient(Patient *patient);
    virtual Patient *getNextPatient() = 0;
protected:
    std::vector<Patient*> _patients;
};


#endif //RERETAKEEXAM3_QUEUE_H

//
// Created by hegye on 2019. 02. 25..
//

#include <cstdlib>
#include "patient.h"

Patient::Patient()
{
    _severity = rand() % 10 + 1;
}

int Patient::getSeverity()
{
    return _severity;
}

void Patient::treat()
{
    if (_severity > 0) {
        _severity--;
    }
}
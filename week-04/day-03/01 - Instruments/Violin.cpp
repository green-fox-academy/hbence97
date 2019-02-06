//
// Created by hegye on 2019. 02. 06..
//

#include "Violin.h"

Violin::Violin()
{
    numberOfStrings = 4;
}

Violin::Violin(int _numberOfStrings)
{
    numberOfStrings = _numberOfStrings;
}

void Violin::sound()
{
    std::cout << "Violin, a " << numberOfStrings << "-stringed instrument that goes Screech" << std::endl;
}
//
// Created by hegye on 2019. 02. 06..
//

#include "BassGuitar.h"


void BassGuitar::sound()
{
    std::cout << "Bass Guitar, a " << numberOfStrings << "-stringed instrument, that goes Duum-duum-duum" << std::endl;
}

BassGuitar::BassGuitar()
{
    numberOfStrings = 4;
}

BassGuitar::BassGuitar(int _numberOfStrings)
{
    numberOfStrings = _numberOfStrings;
}
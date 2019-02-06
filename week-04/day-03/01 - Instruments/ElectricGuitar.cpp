//
// Created by hegye on 2019. 02. 06..
//

#include "ElectricGuitar.h"



void ElectricGuitar::sound()
{
    std::cout << "Electric Guitar, a "<< numberOfStrings << "-stringed instrument that goes Twangg";
}

ElectricGuitar::ElectricGuitar()
{
    numberOfStrings = 6;
}
ElectricGuitar::ElectricGuitar(int _NumberOfStrings)
{
    numberOfStrings = _NumberOfStrings;
}
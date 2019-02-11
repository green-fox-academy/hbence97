//
// Created by hegye on 2019. 02. 11..
//

#include "pirate.h"

Pirate::Pirate(std::string name, bool isCaptain, bool hasWoodenLeg)
{
    _name = name;
    _isCaptain = isCaptain;
    _hasWoodenLeg = hasWoodenLeg;
    _gold = 0;
    _healthPoints = 100;
}

std::string Pirate::toString()
{
    if(_hasWoodenLeg){
        return "Hello, I'm " + _name + " I have a wooden leg ,and I have " + std::to_string(_gold) + " gold.";
    } else {
        return "Hello, I'm " + _name + " I still have my real legs, and " + std::to_string(_gold) + " gold.";
    }
}

std::string Pirate::getName()
{
    return _name;
}

int Pirate::getGold()
{
    return _gold;
}

void Pirate::work()
{
    if(_isCaptain) {
        _gold += 10;
        _healthPoints -= 5;
    } else {
        _gold++;
        _healthPoints--;
    }
}

void Pirate::party()
{
    if(_isCaptain) {
        _healthPoints += 10;
    } else {
        _healthPoints++;
    }
}

bool Pirate::isCaptain()
{
    return _isCaptain;
}

bool Pirate::hasWoodenLeg()
{
    return _hasWoodenLeg;
}
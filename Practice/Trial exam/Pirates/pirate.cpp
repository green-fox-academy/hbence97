//
// Created by hegye on 2019. 02. 10..
//

#include "pirate.h"

Pirate::Pirate(std::string name, bool isCaptain, bool hasWoodenLeg)
{
    _name = name;
    _isCaptain = isCaptain;
    _hasWoodenLeg = hasWoodenLeg;
    _healthPoints = 10;
    _gold = 0;
}

void Pirate::work()
{
    if (_isCaptain) {
        _gold += 10;
        _healthPoints -= 5;
    }else{
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

std::string Pirate::toString()
{
    if (_hasWoodenLeg) {
        return "Hello, I'm " + _name + ". I have a wooden leg and " + std::to_string(_gold) + " golds.";
    } else {
        return "Hello, I'm " + _name + ". I still have my real legs and " + std::to_string(_gold) + " golds.";
    }
}

int Pirate::getGold()
{
    return _gold;
}

bool Pirate::isCaptain()
{
    return _isCaptain;
}

bool Pirate::hasWoodenLeg()
{
    return _hasWoodenLeg;
}

std::string Pirate::getName()
{
    return _name;
}
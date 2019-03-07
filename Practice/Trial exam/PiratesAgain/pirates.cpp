//
// Created by hegye on 2019. 02. 11..
//

#include "pirates.h"

Pirates::Pirates(std::string name, bool isCaptain, bool hasWoodenLeg)
{
    _name = name;
    _isCaptain = isCaptain;
    _hasWoodenLeg = hasWoodenLeg;
    _healthPoints = 100;
    _gold = 10;
}

std::string Pirates::toString()
{
    if(_hasWoodenLeg) {
        return "Hello, I'm " + _name + ". I have a wooden leg and" + std::to_string(_gold) + " golds.";
    } else {
        return "Hello, I'm " + _name + ". I still have my real legs and" + std::to_string(_gold) + " golds.";
    }
}

void Pirates::work()
{
    if(_isCaptain) {
        _gold += 10;
        _healthPoints -= 5;
    } else {
        _gold++;
        _healthPoints--;
    }
}

void Pirates::party()
{
    if(_isCaptain) {
        _healthPoints += 10;
    } else {
        _healthPoints++;
    }
}

int Pirates::getGold()
{
    return _gold;
}

std::string Pirates::getName()
{
    return _name;
}

bool Pirates::hasWoodenLeg()
{
    return _hasWoodenLeg;
}

bool Pirates::isCaptain()
{
    return _isCaptain;
}

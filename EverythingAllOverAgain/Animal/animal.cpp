//
// Created by hegye on 2019. 02. 24..
//

#include "animal.h"

Animal::Animal(std::string name, int hunger, int thirst)
{
    _name = name;
    _hunger = hunger;
    _thirst = thirst;
}

void Animal::drink()
{
    _thirst -= 1;
}

void Animal::eat()
{
    _hunger -= 1;
}

void Animal::play()
{
    _thirst += 1;
    _hunger += 1;
}

std::string Animal::toString()
{
    return "the new animal is  a " + _name + " and their thirst and hunger are " + std::to_string(_thirst) + " " + std::to_string(_hunger);
}
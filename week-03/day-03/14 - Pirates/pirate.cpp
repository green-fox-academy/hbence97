//
// Created by hegye on 2019. 02. 11..
//

#include "pirate.h"

Pirate::Pirate(std::string name, int drunkLevel)
{
    _name = name;
    _drunkLevel = drunkLevel;
}

void Pirate::drinkSomeRum()
{
    _drunkLevel++;
}

bool Pirate::howsItGoingMate()
{
    if(_drunkLevel < 4){
        return "Pour me anudder!";
        drinkSomeRum();
    } else {
        return "Arghh, I'ma Pirate. How d'ya d'ink its goin?";
        passesOut();
    }
}

void Pirate::die()
{
    _isDead = true;
}

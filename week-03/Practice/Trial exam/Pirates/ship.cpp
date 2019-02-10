//
// Created by hegye on 2019. 02. 10..
//

#include "ship.h"
#include "pirate.h"

void Ship::addPirate(Pirate pirate) {
    // Only add him/her if there isn't already a captain on the ship
    if(pirate.isCaptain()){
        for(int i = 0; i < _pirates.size(); i++){
            if(_pirates[i].isCaptain()){

            }
        }
    }
    _pirates.push_back(pirate);
}

std::vector<std::string> Ship::getPoorPirates()
{
    std::vector<std::string> poorPirateNames;
    for(int i = 0; i < _pirates.size(); i++){
        if(_pirates[i].hasWoodenLeg() &&_pirates[i].getGold() < 15){
            poorPirateNames.push_back(_pirates[i].getName());
        }
    }
    return poorPirateNames;
}

int Ship::getGolds()
{
    int totalGold = 0;
    for(int i = 0; i < _pirates.size(); i++){
        totalGold += _pirates[i].getGold();
    }
    return totalGold;
}

void Ship::lastDayOnTheShip()
{
    for(int i = 0;i < _pirates.size(); i++){
        _pirates[i].party();
    }
}

void Ship::prepareForBattle()
{
    for (int i = 0; i < _pirates.size(); i++)
    {
        for(int j = 0; j < 5; j++){
            _pirates[i].work();
        }
    }
    lastDayOnTheShip();
}
//
// Created by hegye on 2019. 02. 11..
//

#include "ship.h"

void Ship::addPirates(Pirate pirate)
{
    if(pirate.isCaptain()) {
        for (int i = 0; i < _pirate.size(); ++i) {
            if(_pirate[i].isCaptain()) ;
        }
    }
    _pirate.push_back(pirate);
}

std::vector<std::string> Ship::getPoorPirates() {
    std::vector<std::string> poorPirates;
    for(int i = 0; i < _pirate.size(); i++){
        if(_pirate[i].hasWoodenLeg() && _pirate[i].getGold() < 15) {
            poorPirates.push_back(_pirate[i].getName());
        }
    }
    return poorPirates;
}

int Ship::getGolds() {
    int totalGold = 0;
    for (int i = 0; i < _pirate.size(); ++i) {
        totalGold = _pirate[i].getGold();
    }
    return totalGold;
}

void Ship::lastDayOnTheShip()
{
    for (int i = 0; i < _pirate.size() ; ++i) {
        _pirate[i].party();
    }
}

void Ship::prepareForBattle()
{
    for (int i = 0; i < _pirate.size(); i++){
        for (int j = 0; j < 5; ++j) {
            _pirate[i].work();
        }
    }
    lastDayOnTheShip();
}
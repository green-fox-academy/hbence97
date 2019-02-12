//
// Created by hegye on 2019. 02. 11..
//

#ifndef PIRATES3RD_SHIP_H
#define PIRATES3RD_SHIP_H

#include <iostream>
#include <vector>
#include "pirate.h"

class Ship {
    std::vector<Pirate> _pirate;

public:
    void addPirates(Pirate pirate);
    std::vector<std::string> getPoorPirates();
    int getGolds();
    void lastDayOnTheShip();
    void prepareForBattle();

};


#endif //PIRATES3RD_SHIP_H

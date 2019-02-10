//
// Created by hegye on 2019. 02. 10..
//

#ifndef PIRATES_SHIP_H
#define PIRATES_SHIP_H

#include <iostream>
#include <vector>
#include "pirate.h"

class Ship {
    std::vector<Pirate> _pirates;

public:
    void addPirate(Pirate pirate);
    std::vector<std::string> getPoorPirates();
    int getGolds();
    void lastDayOnTheShip();
    void prepareForBattle();

};


#endif //PIRATES_SHIP_H

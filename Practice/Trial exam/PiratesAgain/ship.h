//
// Created by hegye on 2019. 02. 11..
//

#ifndef PIRATESAGAIN_SHIP_H
#define PIRATESAGAIN_SHIP_H

#include <iostream>
#include <vector>
#include "pirates.h"

class Ship {
    std::vector<Pirates> _pirates;
public:
    void addPirates(Pirates pirates);
    std::vector <std::string> getPoorPirate();
    int getGolds();
    void lastDayOnTheShip();
    void prepareForBattle();
};


#endif //PIRATESAGAIN_SHIP_H

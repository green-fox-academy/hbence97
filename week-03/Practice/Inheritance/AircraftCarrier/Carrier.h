//
// Created by hegye on 2019. 02. 12..
//

#ifndef AIRCRAFTCARRIER_CARRIER_H
#define AIRCRAFTCARRIER_CARRIER_H

#include <iostream>
#include <vector>
#include "Aircraft.h"

class Carrier {
private:
    int _ammoStore;
    std::vector<Aircraft>_aircrafts;
public:
    Carrier(int ammo, int healthPoints);
    void addAircraft(Aircraft aircrafts);
    int fill();
    void fight();
    std::string getStatus();
    int getCurrentAmmo();
};


#endif //AIRCRAFTCARRIER_CARRIER_H

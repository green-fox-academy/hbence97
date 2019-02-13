//
// Created by hegye on 2019. 02. 12..
//

#ifndef AIRCRAFTCARRIER_AIRCRAFTS_H
#define AIRCRAFTCARRIER_AIRCRAFTS_H

#include <iostream>

class aircrafts {
    int ammo;
public:
    virtual int fight() = 0;
    virtual int refill(int a) = 0;
    virtual std::string getType() = 0;
    virtual std::string getStatus() = 0;
    virtual bool isPriority() = 0;
};


#endif //AIRCRAFTCARRIER_AIRCRAFTS_H

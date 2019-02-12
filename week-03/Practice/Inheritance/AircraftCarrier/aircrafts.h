//
// Created by hegye on 2019. 02. 12..
//

#ifndef AIRCRAFTCARRIER_AIRCRAFTS_H
#define AIRCRAFTCARRIER_AIRCRAFTS_H

#include <iostream>

class aircrafts {
    int ammo;
public:
    virtual int fight();
    virtual int refill(int a);
    virtual std::string getType();
    virtual std::string getStatus();
    virtual bool isPriority();
};


#endif //AIRCRAFTCARRIER_AIRCRAFTS_H

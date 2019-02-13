//
// Created by hegye on 2019. 02. 12..
//

#ifndef AIRCRAFTCARRIER_AIRCRAFTS_H
#define AIRCRAFTCARRIER_AIRCRAFTS_H

#include <iostream>

class Aircraft {
    int ammo;
    int _type;
public:
    Aircraft(std::string type);
    virtual int fight() = 0;
    virtual int refill(int a) = 0;
    virtual std::string getType() = 0;
    virtual std::string getStatus() = 0;
    virtual bool isPriority() = 0;
    virtual int getCurrentAmmo();
    virtual int baseDamage();
};


#endif //AIRCRAFTCARRIER_AIRCRAFTS_H

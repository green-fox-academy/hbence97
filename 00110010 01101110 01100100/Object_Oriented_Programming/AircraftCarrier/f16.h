//
// Created by hegye on 2019. 07. 04..
//

#ifndef AIRCRAFTCARRIER_F16_H
#define AIRCRAFTCARRIER_F16_H

#include <iostream>

class F16 {
    int _maxAmmo = 8;
    int _baseDamage = 30;
    std::string _type;
public:
    int fight();
    int refill(int refillAmount);
    std::string getType();
    std::string getStatus(std::string type, int ammo, int basedamage, int allDamage);
    bool isPriority();
};

#endif //AIRCRAFTCARRIER_F16_H

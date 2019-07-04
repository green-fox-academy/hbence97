//
// Created by hegye on 2019. 07. 04..
//

#ifndef AIRCRAFTCARRIER_F35_H
#define AIRCRAFTCARRIER_F35_H

#include <iostream>

class F35 {
    int _maxAmmo = 12;
    int _baseDamage = 50;
    std::string _type;
public:
    int fight();
    int refill(int refillAmount);
    std::string getType();
    std::string getStatus(std::string type, int ammo, int basedamage, int allDamage);
    bool isPriority();
};


#endif //AIRCRAFTCARRIER_F35_H

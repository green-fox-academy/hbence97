//
// Created by hegye on 2019. 02. 12..
//

#ifndef AIRCRAFTCARRIER_F35_H
#define AIRCRAFTCARRIER_F35_H


#include "aircrafts.h"

class F35 : public aircrafts {
protected:
    int maxAmmo = 12;
    int baseDamage = 50;
public:
    int fight() override;
    int refill(int a) override;
    std::string getType() override;
    std::string getStatus() override;
    bool isPriority() override;
};


#endif //AIRCRAFTCARRIER_F35_H

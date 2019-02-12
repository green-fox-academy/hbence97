//
// Created by hegye on 2019. 02. 12..
//

#ifndef AIRCRAFTCARRIER_F16_H
#define AIRCRAFTCARRIER_F16_H


#include "aircrafts.h"

class F16 : public aircrafts{
protected:
    int maxAmmo = 8;
    int baseDamage = 30;
public:
    int fight() override;
    int refill(int a) override;
    std::string getType() override;
    std::string getStatus() override;
    bool isPriority() override;
};


#endif //AIRCRAFTCARRIER_F16_H

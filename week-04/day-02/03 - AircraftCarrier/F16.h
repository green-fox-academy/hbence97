//
// Created by hegye on 2019. 02. 08..
//

#ifndef INC_03_AIRCRAFTCARRIER_F16_H
#define INC_03_AIRCRAFTCARRIER_F16_H


#include "aircrafts.h"

class F16 : public aircrafts{
protected:
    int maxAmmo;
    int baseDamage;
public:
    F16();
    int fight() override;
    int refill(int a) override;
    std::string getType();
    std::string getStatus();
    bool isPriority();

};


#endif //INC_03_AIRCRAFTCARRIER_F16_H

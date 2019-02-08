//
// Created by hegye on 2019. 02. 08..
//

#ifndef INC_03_AIRCRAFTCARRIER_F35_H
#define INC_03_AIRCRAFTCARRIER_F35_H

#include "aircrafts.h"

class F35 : public aircrafts{
protected:
    int maxAmmo;
    int baseDamage;
public:
    int fight() override;
    int refill(int b) override;
    std::string getType();
    std::string getStatus();
    bool isPriority();

};

#endif //INC_03_AIRCRAFTCARRIER_F35_H

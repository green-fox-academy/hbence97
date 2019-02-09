//
// Created by hegye on 2019. 02. 09..
//

#ifndef INC_03_AIRCRAFTCARRIER_CARRIER_H
#define INC_03_AIRCRAFTCARRIER_CARRIER_H


class carrier {
    int storeAircrafts;
    int storeOfAmmo;
public:
    carrier initialAmmo(int ammo);
    carrier healhPoint();
    int add();
    int fill();
    int fight();
    std::string getStatus();
};


#endif //INC_03_AIRCRAFTCARRIER_CARRIER_H

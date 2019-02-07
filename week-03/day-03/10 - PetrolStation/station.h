//
// Created by hegye on 2019. 02. 07..
//

#ifndef INC_10_PETROLSTATION_STATION_H
#define INC_10_PETROLSTATION_STATION_H


#include "car.h"

class station {
    int gasAmount;
public:
    station();
    int fill(car _car);

};


#endif //INC_10_PETROLSTATION_STATION_H

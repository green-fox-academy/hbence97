//
// Created by hegye on 2019. 02. 07..
//

#ifndef INC_10_PETROLSTATION_STATION_H
#define INC_10_PETROLSTATION_STATION_H

#include "Car.h"

class Station{
    int gasAmount;
public:
    Station();
    int fill(Car car);

};


#endif //INC_10_PETROLSTATION_STATION_H

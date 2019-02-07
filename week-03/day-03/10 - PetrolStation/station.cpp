//
// Created by hegye on 2019. 02. 07..
//

#include <iostream>
#include "station.h"
#include "car.h"

station::station()
{
    gasAmount = 100;
}


int station::fill(car _car){
    while (!_car.isFull())
    {
        _car.fill();
        gasAmount --;
        std::cout << "Filling car!" << std::endl;
    }
    std::cout << gasAmount << std::endl;
}
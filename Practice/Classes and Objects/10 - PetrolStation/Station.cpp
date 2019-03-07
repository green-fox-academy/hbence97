//
// Created by hegye on 2019. 02. 07..
//

#include <iostream>
#include "Station.h"

Station::Station()
{
    gasAmount = 100;
}

int Station::fill(Car car)
{
    while(!car.isFull())
    {
        car.fill();
        gasAmount --;
        std::cout << "Filling car" << std::endl;
    }
    std::cout << gasAmount << std::endl;
}
//
// Created by hegye on 2019. 02. 07..
//

#include "Car.h"

bool Car::isFull()
{
    if (capacity == gasAmount)
    return true;
}

void Car::fill()
{
    gasAmount ++;
}

Car::Car(int _gasAmount, int _capacity)
{
    gasAmount = _gasAmount;
    capacity = _capacity;
}


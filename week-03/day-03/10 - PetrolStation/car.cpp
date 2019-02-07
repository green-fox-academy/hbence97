//
// Created by hegye on 2019. 02. 07..
//

#include "car.h"

bool car::isFull(){

    //if(capacity() == gasAmount())
      //  return true;
    //else return false;
    return  capacity == gasAmount;
}

void car::fill()
{
    gasAmount++;
}

car::car(int _gasAmount, int _capacity)
{
    gasAmount = _gasAmount;
    capacity = _capacity;
}
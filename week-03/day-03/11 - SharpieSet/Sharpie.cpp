//
// Created by hegye on 2019. 02. 09..
//

#include "Sharpie.h"

void Sharpie::use()
{
    inkAmount --;
}

Sharpie::Sharpie(std::string _color, float _width)
{
    color = _color;
    width = _width;

    std::cout << "The color you chose was" << _color << " and the width is " << _width << "and the ink amount is " << inkAmount<< std::endl;
}

bool Sharpie::isEmpty()
{
    inkAmount == 0;
    return true;
}
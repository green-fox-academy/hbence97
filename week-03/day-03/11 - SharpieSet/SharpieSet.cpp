//
// Created by hegye on 2019. 02. 09..
//
#include <iostream>
#include "SharpieSet.h"
#include "Sharpie.h"

/*Sharpie::Sharpie(std::string _color, float _width) {
    color = _color;
    width = _width;

    std::cout << "The color you chose was" << _color << " and the width is " << _width << "and the ink amount is "
              << inkAmount << std::endl;
}*/

void SharpieSet::usable()
{
    if (inkAmount > 0)
        std::cout << "This sharpie still has ink in it. You can use it." << std::endl;
}

void SharpieSet::removeTrash()
{
    
}
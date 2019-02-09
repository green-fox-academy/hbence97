//
// Created by hegye on 2019. 02. 09..
//

#ifndef INC_11_SHARPIESET_SHARPIE_H
#define INC_11_SHARPIESET_SHARPIE_H

#include <iostream>

class Sharpie {
protected:
    std::string color;
    float width;
    std::string type;
public:
    int inkAmount = 100;
    void use();
    bool isEmpty();
    Sharpie(std::string _color, float _width);
};


#endif //INC_11_SHARPIESET_SHARPIE_H

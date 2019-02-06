//
// Created by hegye on 2019. 02. 06..
//

#ifndef INC_01_INSTRUMENTS_INSTRUMENT_H
#define INC_01_INSTRUMENTS_INSTRUMENT_H

#include <iostream>

class instrument {
protected:
    std::string name;
public:
    virtual void play() = 0;
};


#endif //INC_01_INSTRUMENTS_INSTRUMENT_H

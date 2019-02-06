//
// Created by hegye on 2019. 02. 06..
//

#ifndef INC_01_INSTRUMENTS_STRINGEDINSTRUMENTS_H
#define INC_01_INSTRUMENTS_STRINGEDINSTRUMENTS_H


#include "instrument.h"

class stringedInstruments: public instrument {
protected:
    int numberOfStrings;

public:
    virtual void sound() = 0;
    virtual void play() override;

};


#endif //INC_01_INSTRUMENTS_STRINGEDINSTRUMENTS_H

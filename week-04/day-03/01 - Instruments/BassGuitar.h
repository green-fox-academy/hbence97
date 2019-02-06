//
// Created by hegye on 2019. 02. 06..
//

#ifndef INC_01_INSTRUMENTS_BASSGUITAR_H
#define INC_01_INSTRUMENTS_BASSGUITAR_H


#include "stringedInstruments.h"

class BassGuitar : public stringedInstruments{
public:
    BassGuitar();
    BassGuitar(int numberOfStrings);
    void sound() override;
};


#endif //INC_01_INSTRUMENTS_BASSGUITAR_H

//
// Created by hegye on 2019. 02. 06..
//

#ifndef INC_01_INSTRUMENTS_ELECTRICGUITAR_H
#define INC_01_INSTRUMENTS_ELECTRICGUITAR_H

#include "stringedInstruments.h"

class ElectricGuitar : public stringedInstruments {
public:
    ElectricGuitar();
    ElectricGuitar(int NumberOfStrings);
    void sound() override;

};


#endif //INC_01_INSTRUMENTS_ELECTRICGUITAR_H

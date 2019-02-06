//
// Created by hegye on 2019. 02. 06..
//

#ifndef INC_01_INSTRUMENTS_VIOLIN_H
#define INC_01_INSTRUMENTS_VIOLIN_H


#include "stringedInstruments.h"

class Violin : public stringedInstruments{
public:
    Violin();
    Violin(int numberOfStrings);
    void sound () override;


};


#endif //INC_01_INSTRUMENTS_VIOLIN_H

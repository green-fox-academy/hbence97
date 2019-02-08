//
// Created by hegye on 2019. 02. 08..
//

#ifndef INC_03_AIRCRAFTCARRIER_AIRCRAFTS_H
#define INC_03_AIRCRAFTCARRIER_AIRCRAFTS_H

#include <iostream>

class aircrafts {
protected:
    int ammoStore;
public:
    virtual int fight() = 0;
    virtual int refill(int a) = 0;
    virtual std::string getType() = 0;
    virtual std::string getStatus() = 0;
    virtual bool isPriority() = 0;

};


#endif //INC_03_AIRCRAFTCARRIER_AIRCRAFTS_H

//
// Created by hegye on 2019. 02. 11..
//

#ifndef INC_14_PIRATES_PIRATE_H
#define INC_14_PIRATES_PIRATE_H

#include <iostream>

class Pirate {
    std::string _name;
    int _drunkLevel;
    void _isDead;
public:
    Pirate(std::string name, int drunkLevel);
    void drinkSomeRum();
    bool howsItGoingMate();
    void passesOut();
    void die();
};


#endif //INC_14_PIRATES_PIRATE_H

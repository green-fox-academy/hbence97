//
// Created by hegye on 2019. 02. 10..
//

#ifndef PIRATES_PIRATE_H
#define PIRATES_PIRATE_H

#include <iostream>

class Pirate {
    std::string _name;
    int _gold;
    int _healthPoints;
    bool _isCaptain;
    bool _hasWoodenLeg;
public:
    Pirate(std::string name, bool isCaptain, bool hasWoodenLeg);

    void work();
    void party();
    std::string toString();

    int getGold();
    std::string getName();
    bool isCaptain();
    bool hasWoodenLeg();


};


#endif //PIRATES_PIRATE_H

//
// Created by hegye on 2019. 02. 11..
//

#ifndef PIRATES3RD_PIRATE_H
#define PIRATES3RD_PIRATE_H

#include <iostream>

class Pirate {
    std::string _name;
    int _age;
    int _gold;
    int _healthPoints;
    bool _isCaptain;
    bool _hasWoodenLeg;

public:
    Pirate (std::string name, bool isCaptain, bool hasWoodenLeg);
    std::string toString();
    std::string getName();
    int getGold();
    void work();
    void party();
    bool isCaptain();
    bool hasWoodenLeg();
};


#endif //PIRATES3RD_PIRATE_H

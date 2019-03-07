//
// Created by hegye on 2019. 02. 13..
//

#ifndef PIRATES4TH_PIRATES_H
#define PIRATES4TH_PIRATES_H

#include <iostream>

class Pirates {
    std::string _name;
    int _amountOfGold;
    int _healthPoints;
    bool _hasWoodenLeg;
    bool _isCaptain;
public:
    Pirates(std::string _name, int _amountOfGold, int healthPoints);
    std::string toString();
    void work();
    void party();
    std::string getName();
    int getHealthPoints();
    bool isCaptain();
    bool hasWoodenLeg();
};


#endif //PIRATES4TH_PIRATES_H

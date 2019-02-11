//
// Created by hegye on 2019. 02. 11..
//

#ifndef PIRATESAGAIN_PIRATES_H
#define PIRATESAGAIN_PIRATES_H

#include <iostream>

class Pirates {
    std::string _name;
    int _age;
    int _gold;
    int _healthPoints;
    bool _isCaptain;
    bool _hasWoodenLeg;
public:
    Pirates(std::string name, bool isCaptain, bool hasWoodenLeg);
    std::string toString();
    void work();
    void party();
    std::string getName();
    int getGold();
    int getHealthPoints();
    bool isCaptain();
    bool hasWoodenLeg();
};


#endif //PIRATESAGAIN_PIRATES_H

//
// Created by hegye on 2019. 02. 24..
//

#ifndef ANIMAL_ANIMAL_H
#define ANIMAL_ANIMAL_H

#include <iostream>

class Animal {
    int _hunger = 50;
    int _thirst = 50;
    std::string _name;
public:
    Animal(std::string name, int hunger, int thirst);
    void eat();
    void drink();
    void play();
    std::string toString();
};


#endif //ANIMAL_ANIMAL_H

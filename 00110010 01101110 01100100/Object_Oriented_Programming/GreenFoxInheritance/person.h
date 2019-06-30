//
// Created by hegye on 2019. 06. 30..
//
#ifndef GREENFOXINHERITANCE_PERSON_H
#define GREENFOXINHERITANCE_PERSON_H
#include <iostream>

enum gender{
    MALE = 1,
    FEMALE = 2
};

class Person {
protected:
    std::string _name;
    int _age;
    gender _gender;
public:
    Person(std::string name, int age, gender gender);
    Person();
    virtual void introduce();
    virtual void getGoal();
};


#endif //GREENFOXINHERITANCE_PERSON_H

//
// Created by hegye on 2019. 02. 05..
//

#ifndef INC_00_PERSON_PERSON_H
#define INC_00_PERSON_PERSON_H

#include <iostream>
#include <string>
enum GENDER {
    MALE,
    FEMALE
};

class Person {
protected:
    std::string name;
    int age;
    GENDER gender;
public:
    Person(std::string name, int age,GENDER gender);
    Person();
    virtual void introduce();
    virtual void getGoal();




};


#endif //INC_00_PERSON_PERSON_H

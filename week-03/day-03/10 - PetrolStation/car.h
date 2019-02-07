//
// Created by hegye on 2019. 02. 07..
//

#ifndef INC_10_PETROLSTATION_CAR_H
#define INC_10_PETROLSTATION_CAR_H


class car {
    int gasAmount;
    int capacity;
public:
    car (int gasAmount,int capacity);
    void fill();
    bool isFull();
};


#endif //INC_10_PETROLSTATION_CAR_H

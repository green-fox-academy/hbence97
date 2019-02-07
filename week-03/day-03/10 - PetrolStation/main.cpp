#include <iostream>
#include "car.h"
#include "station.h"
int main() {

    car car1(50, 100);
    car car2(80,100);
    station station1;
    station1.fill(car1);
    station1.fill(car2);

    return 0;
}
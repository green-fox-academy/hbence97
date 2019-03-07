#include <iostream>
#include "Station.h"
#include "Car.h"

int main()
{
    Car car1(50,60);
    Car car2(70,100);
    Station station1;
    station1.fill(car1);
    station1.fill(car2);

    return 0;
}
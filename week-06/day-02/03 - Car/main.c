#include <stdio.h>

// Write a function that takes a car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

enum car_type {VOLVO, TOYOTA, LAND_ROVER, TESLA};

typedef struct {
    enum car_type type;
    double km;
    double gas;
} Car;

void GasLevel(Car car);

int main()
{
    Car car1;
    Car car2;
    Car car3;
    Car car4;

    car1.type = VOLVO;
    car1.km = 16230;
    car1.gas = 34;

    car2.type = TOYOTA;
    car2.km = 156165;
    car2.gas = 15;

    car3.type = LAND_ROVER;
    car3.km = 67415;
    car3.gas = 56;

    car4.type = TESLA;
    car4.km = 25143;

    GasLevel(car1);
    GasLevel(car4);


    return 0;
}

void GasLevel(Car car) {
    if (car.type == TESLA) {
        printf("Its an electronic car");
    } else {
        printf("The amount of gas the car has is: %.0f\n",car.gas );
    }
}
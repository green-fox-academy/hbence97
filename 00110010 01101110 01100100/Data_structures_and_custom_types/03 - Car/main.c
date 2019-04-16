#include <stdio.h>

// Write a function that takes a car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

enum car_type {
    VOLVO,
    TOYOTA,
    LAND_ROVER,
    TESLA
};

typedef struct {
    enum car_type type;
    double km;
    double gas;
} Car;

void gas_level(Car car)
{
    if(car.type == TESLA){
        printf("It's an electronic car.\n");
    } else {
        printf("The gas amount is %.2f liters.\n", car.gas);
    }
}

int main()
{
    Car car1;
    Car car2;
    Car car3;

    car1.type = TESLA;
    car1.km = 24560;

    car2.type = VOLVO;
    car2.gas = 35.5;
    car2.km = 75000;

    car3.type = LAND_ROVER;
    car3.gas = 50;
    car3.km = 85530;

    gas_level(car1);
    gas_level(car2);
    gas_level(car3);

    return 0;
}
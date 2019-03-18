#include <stdio.h>
#include <string.h>
#include <comip.h>

enum transmission_t {MANUAL, AUTOMATIC, CVT, SEMI_AUTOMATIC, DUAL_CLUTCH};

typedef struct {
    enum transmission_t transmission;
    char name[256];
    float price;
    int year;
} car_t;

int get_cars_older_than(car_t* cars, int array_length, int age)
{
    int older = 0;
    for(int i = 0; i < array_length; ++i){
        if(cars[i].year < 2019 - age){
            older++;
        }
    }
    return older;
}

int get_transmission_count(car_t* cars, int array_length, enum transmission_t transmission)
{
    int transmission_result = 0;
    for (int i = 0; i < array_length; ++i) {
        if (cars[i].transmission == transmission){
            transmission_result++;
        }
    }
    return transmission_result;
}

int main()
{
    car_t *cars = (car_t*) calloc(3, sizeof(car_t));

    car_t car1;
    car_t car2;
    car_t car3;

    strcpy(car1.name,"Ferrari");
    car1.transmission = DUAL_CLUTCH;
    car1.price = 650000;
    car1.year = 2017;
    cars[0] = car1;

    strcpy(car2.name, "BMW");
    car2.transmission = AUTOMATIC;
    car2.price = 90000;
    car2.year = 2016;
    cars[1] = car2;

    strcpy(car3.name, "Peugeot");
    car3.transmission = MANUAL;
    car3.price = 1600;
    car3.year = 2003;
    cars[2] = car3;

    printf("The number of cars that are older then the given age: %d", get_cars_older_than(cars, 3, 2));


    return 0;
}
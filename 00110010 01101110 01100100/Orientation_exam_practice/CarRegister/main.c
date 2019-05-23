#include <stdio.h>

typedef enum {
    MANUAL,
    AUTOMATIC,
    CVT,
    SEMI_AUTOMATIC,
    DUAL_CLUTCH
} transmission_e;

typedef struct {
    char manufacturers_name[255];
    float car_price;
    int year_of_manufacture;
    transmission_e transmission;
} car_t;

int get_cars_older_than(car_t* cars, int array_length, int age);
int get_transmission_count(car_t* cars, int array_length, transmission_e transmission);

int main() {

    car_t car[3];
    car[0].transmission = MANUAL;
    car[0].year_of_manufacture = 1997;
    car[0].car_price = 6234623;

    car[1].transmission = DUAL_CLUTCH;
    car[1].year_of_manufacture = 2018;
    car[1].car_price = 6234623;

    car[2].transmission = MANUAL;
    car[2].year_of_manufacture = 2005;
    car[2].car_price = 6234623;

    printf("%d\n",get_cars_older_than(car,3,3));
    printf("%d\n", get_transmission_count(car,3,DUAL_CLUTCH));

    return 0;
}

int get_cars_older_than(car_t* cars, int array_length, int age)
{
    int older = 0;
    int current_year = 2019;

    for (int i = 0; i < array_length; ++i) {
        if (age < current_year - cars[i].year_of_manufacture){
            older++;
        }
    }
    return older;
}

int get_transmission_count(car_t* cars, int array_length, transmission_e transmission)
{
    int counter = 0;

    for (int i = 0; i < array_length; ++i) {
        if (cars[i].transmission == transmission){
            counter++;
        }
    }
    return counter;
}
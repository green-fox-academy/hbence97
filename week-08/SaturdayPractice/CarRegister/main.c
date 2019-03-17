#include <stdio.h>

enum transmission_t {MANUAL, AUTOMATIC, CVT, SEMI-AUTOMATIC, DUAL-CLUTCH};

typedef struct {
    enum transmission_t transmission;
    char name[256];
    float price;
    int year;
} car_t;

get_cars_older_than(car_t* cars, int array_length, int age)
{
    int currentYear = 2019;
    int older = 0;

    for(int i = 0; i < array_length; ++i){
        int car_age = currentYear - age;
        if (car_age > age) {
            older++;
        }
    }
    return older;
}


int main() {

    return 0;
}
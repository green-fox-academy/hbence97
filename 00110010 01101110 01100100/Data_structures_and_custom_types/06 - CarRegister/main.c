#include <string.h>
#include <stdio.h>
#include <comip.h>

/* Write a car register!
 * You should store the following data in a structure, called "car":
 *  - the manufacturer's name (which is shorter than 256 characters)
 *  - the price of the car (in euros, stored as a floating point number)
 *  - the year of manufacture
 *  - the type of the transmission (as a custom type, see below)
 *
 * You should store the transmission type in an enumeration ("transmission"),
 * the valid types are:
 *  - manual
 *  - automatic
 *  - CVT
 *  - semi-automatic
 *  - dual-clutch
 *
 * The "car"-s are stored in an array.
 *
 * Write the following functions:
 *  - get_older_cars_than(struct car* array, int array_length, int age)
 *      - it returns the count of the older cars than "age"
 *  - get_transmission_count(struct car* array, int array_length, enum transmission trnsm)
 *      - it returns the count of cars which has "trnsm" transmission
 */

enum transmission{
    MANUAL,
    AUTOMATIC,
    CVT,
    SEMI_AUTOMATIC,
    DUAL_CLUTCH
};

typedef struct car{
    char name[256];
    float price;
    int year;
    enum transmission type;
} car_t;

int get_older_cars_than(struct car* array, int array_length, int age)
{
    int count = 0;
    int current_year = 2019;
    for (int i = 0; i < array_length; ++i) {
        int car_age = current_year - array[i].year;
        if(car_age > age) {
            count++;
        }
    }
    return count;
}

int get_transmission_count(struct car* array, int array_length, enum transmission trnsm)
{
    int trnsm_count = 0;
    for (int i = 0; i < array_length; ++i) {
        if (array[i].type == trnsm){
            trnsm_count++;
        }
    }
    return trnsm_count;
}

int main()
{
    car_t cars[3];

    cars[0].year = 2016;
    cars[1].year = 1997;
    cars[2].year = 2010;

    int cars_length = sizeof(cars) / sizeof(*cars);

    printf("Found %d older cars\n", get_older_cars_than(cars, cars_length, 10));

    cars[0].type = DUAL_CLUTCH;
    cars[1].type = MANUAL;
    cars[2].type = AUTOMATIC;

    printf("Found %d car(s) with this transmission type\n", get_transmission_count(cars, cars_length, DUAL_CLUTCH));

    return 0;
}
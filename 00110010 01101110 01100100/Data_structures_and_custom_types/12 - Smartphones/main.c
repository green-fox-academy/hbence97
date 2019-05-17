#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Create a smartphone register application
 * Read the content of smartphones.txt and store the informations in a structure called "smartphone:
 * - the name of the gadget (which is shorter than 256 characters) (Don't bother with the underscore('_') character, it's the part of the name)
 * - the year of the release (e.g. 2016)
 * - the type of the screen size (as a custom type, see below)
 *
 * In the file the size is given in cm but you should store the screen size type in an enumeration ("screen_size"),
 * the valid types are:
 *  - BIG -> (>= 15 cm)
 *  - MEDIUM -> (>= 12 cm)
 *  - SMALL -> (< 12 cm)
 *
 * The smartphones should be stored in an array.
 *
 * Implement the following functions:
 * - get_oldest_phone()
 *    - it should return the name of oldest device
 *    - it is up to you how your function declaration looks like (return type and arguments)
 * - get_screen_size_count()
 *    - it returns the count of phones which has "screen_size" size
 *    - it is up to you how your function declaration looks like (return type and arguments)
 *
 * Your main function should invoke these functions and print the following:
 * The ..... is the oldest device in the database
 * There are .... phones with BIG (>= 15 cm) screen size
 * There are .... phones with SMALL (< 12 cm) screen size
 *
 *
 * Additionally, you need to create a new file(prices.txt) that looks like this:
 * <NAME> <PRICE>
 * <NAME> <PRICE>
 * .
 * .
 * .
 *
 * To calculate the price use the following method. The base price of every phone is 300$.
 * If the size is SMALL, that adds 0$ to the value
 * If the size is MEDIUM, that adds 100$ to the value
 * If the size is BIG, that doubles the base price.
 *
 * The price also depends on the age. For every year that passed since its release,
 * the phone loses 50$ but the maximum value that it can lose because of the age is 250$
 */
typedef enum {
    BIG,
    MEDIUM,
    SMALL
} screen_size_t;

typedef struct smartphone
{
    char mobile_name[255];
    int year_of_release;
    screen_size_t screen_size;
} smartphone_t;

char* get_oldest_phone(smartphone_t smartphone[], int size);
int get_screen_size_count(smartphone_t smartphone[], screen_size_t screen_size, int size);

int main()
{

    return 0;
}

char* get_oldest_phone(smartphone_t smartphone[], int size)
{
    int oldest = UINT_MAX;
    int index = 0;

    for (int i = 0; i < size; ++i) {
        if(smartphone[i].year_of_release < oldest){
            oldest = smartphone[i].year_of_release;
            index = i;
        }
    }
    return smartphone[index].mobile_name;
}

int get_screen_size_count(smartphone_t smartphone[], screen_size_t screen_size, int size)
{
    int counter = 0;

    for (int i = 0; i < size; ++i) {
        if(smartphone[i].screen_size == screen_size) {
            counter++;
        }
    }
    return counter;
}
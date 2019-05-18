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
    int price;
} smartphone_t;

char* get_oldest_phone(smartphone_t smartphone[], int size);
int get_screen_size_count(smartphone_t smartphone[], screen_size_t screen_size, int size);
void read_into_struct(const char file[], int size, smartphone_t smartphone[]);
void create_new_file(smartphone_t smartphone[], int length);
void calculate_price(smartphone_t smartphone[], int length);

int main()
{
    int size = 0;

    printf("The oldest phone in the database is: %s\n");

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

void read_into_struct(const char file[], int size, smartphone_t smartphone[])
{
    FILE *fp;
    fp = fopen(file, "r");
    if (fp == NULL){
        printf("There was an error opening the file.\n");
        exit(EXIT_FAILURE);
    }
    char buffer[100];
    int i = 0;
    while (!feof(fp)){
        fgets(buffer, 100, fp);
        char* name = strtok(buffer, " ");
        char* release_year = strtok(buffer, " ");
        char* screen_size = strtok(buffer, " ");

        strcpy(smartphone[i].mobile_name, name);
        smartphone[i].year_of_release = atoi(release_year);
        smartphone[i].screen_size = atoi(screen_size);
        if(screen_size >= 15){
            smartphone[i].screen_size = BIG;
        } else if (screen_size >= 12 && screen_size < 15){
            smartphone[i].screen_size = MEDIUM;
        } else if (screen_size < 12){
            smartphone[i].screen_size = SMALL;
        }
        i++;
    }
    fclose(fp);
}

void create_new_file(smartphone_t *smartphone, int length)
{
    FILE *fp;
    fp = fopen("prices.txt", "w");
    if(fp == NULL){
        printf("There was an error oppening the file.\n");
        exit(EXIT_FAILURE);
    }
    calculate_price(smartphone, length);
    for (int i = 0; i < length; ++i) {
        fprintf(fp,"%s %d EUR", smartphone[i].mobile_name, smartphone[i].price);
    }
    fclose(fp);
}

void calculate_price(smartphone_t smartphone[], int length)
{
    int base_price = 300;
    for (int i = 0; i < length; ++i) {
        if (smartphone[i].screen_size == SMALL){
            smartphone[i].price = base_price;
        } else if (smartphone[i].screen_size == MEDIUM){
            smartphone[i].price = base_price + 300;
        } else if (smartphone[i].screen_size == BIG){
            smartphone[i].price = base_price * 2;
        }
    }
    int current_year = 2019;
    for (int j = 0; j < length; ++j) {
        if ((current_year - smartphone[j].year_of_release) > 4 ){
            smartphone[j].price -= 250;
        } else {
            smartphone[j].price -= (current_year - smartphone[j].year_of_release) * 50;
        }
    }
}
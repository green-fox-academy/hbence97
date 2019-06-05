#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    SMALL, // ( < 12cm)
    MEDIUM, // ( >= 12cm && < 15cm)
    BIG  // ( >=  15cm)
} screen_size_e;

typedef struct {
    char name[255];
    int release_year;
    screen_size_e screenSizeE;
} smartphones_t;

smartphones_t get_oldest_phone(smartphones_t *smartphones, int size_of_array);
int get_screen_size_count(screen_size_e screenSizeE, int size_of_array, smartphones_t *smartphones);

int main() {

    smartphones_t smartphone[2];

    strcpy(smartphone[0].name, "Samsung");
    smartphone[0].release_year = 2015;
    smartphone[0].screenSizeE = SMALL;

    strcpy(smartphone[1].name, "Apple");
    smartphone[1].release_year = 2018;
    smartphone[1].screenSizeE = BIG;

    printf("%s\n", get_oldest_phone(smartphone,2));
    printf("%d\n", get_screen_size_count(BIG, 2, smartphone));

    return 0;
}

smartphones_t get_oldest_phone(smartphones_t *smartphones, int size_of_array)
{
    int current_year = 2019;
    int index = 0;

    for (int i = 0; i < size_of_array; ++i) {
        if (smartphones[i].release_year < current_year) {
            current_year = smartphones[i].release_year;
            index = i;
        }
    }
    return smartphones[index];
}

int get_screen_size_count(screen_size_e screenSizeE, int size_of_array, smartphones_t *smartphones)
{
    int counter = 0;

    for (int i = 0; i < size_of_array; ++i) {
        if (smartphones[i].screenSizeE == screenSizeE){
            counter++;
        }
    }
    return counter;
}
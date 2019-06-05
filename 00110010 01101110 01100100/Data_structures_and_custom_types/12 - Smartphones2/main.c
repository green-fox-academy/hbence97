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
    int price;
    screen_size_e screenSizeE;
} smartphones_t;

smartphones_t get_oldest_phone(smartphones_t *smartphones, int size_of_array);
int get_screen_size_count(screen_size_e screenSizeE, int size_of_array, smartphones_t *smartphones);
void calculate_price(int size_of_array, smartphones_t *smartphones);
void creating_a_new_file(char* filename, int size_of_array, smartphones_t *smartphones);

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
    printf("%d\n", get_screen_size_count(SMALL, 2, smartphone));
    creating_a_new_file("prices.txt",2,smartphone);

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

void calculate_price(int size_of_array, smartphones_t *smartphones)
{
    int base_price = 300;
    int current_year = 2019;

    for (int j = 0; j < size_of_array; ++j) {
        if (smartphones[j].screenSizeE == SMALL){
            smartphones[j].price = base_price;
        } else if (smartphones[j].screenSizeE == MEDIUM) {
            smartphones[j].price = base_price + 100;
        } else if (smartphones[j].screenSizeE == BIG) {
            smartphones[j].price = base_price * 2;
        }
    }

    for (int i = 0; i < size_of_array; ++i) {
        if ((current_year - smartphones[i].release_year) > 4) {
            smartphones[i].price = 250;
        } else {
            smartphones[i].price -= (current_year - smartphones[i].release_year)* 50;
        }
    }
}

void creating_a_new_file(char* filename, int size_of_array, smartphones_t *smartphones)
{
    FILE *fptr;
    fptr = fopen(filename, "w");

    if (fptr == NULL){
        printf("There was an error opening the file.\n");
        exit(EXIT_FAILURE);
    }
    calculate_price(size_of_array, smartphones);
    for (int i = 0; i < size_of_array; ++i) {
        fprintf(fptr,"%s %d\n",smartphones[i].name,smartphones[i].price);
    }
    fclose(fptr);
}
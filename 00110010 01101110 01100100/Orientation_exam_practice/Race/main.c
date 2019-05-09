#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
    HANDICAPPED,
    AMATEUR,
    PROFESSIONAL
} category_t;

typedef struct {
    unsigned int start_number;
    category_t category;
    unsigned int finish_time;
} competitor_t;

competitor_t winners(competitor_t* competitor,int size_of_array, category_t category);

int main() {

    srand(time(NULL));
    int competitors_size = rand() % 30 + 30;
    competitor_t competitors[competitors_size];
    for (int i = 0; i < competitors_size; i++) {
        competitors[i].start_number = i + 1;
        competitors[i].category = rand() % 3;
        competitors[i].finish_time = rand() % 2500 + 3000;
    }
    int competitors_length = sizeof(competitors) / sizeof(*competitors);

    printf("There are %d competitors\n", competitors_length);
    printf("The winner in amateur category is the competitor nr. %d.\n", winners(competitors,competitors_size,AMATEUR).start_number);
    printf("The winner in professional category is the competitor nr. %d.\n", winners(competitors,competitors_size,PROFESSIONAL).start_number);
    printf("The winner in handicapped category is the competitor nr. %d.\n", winners(competitors,competitors_size,HANDICAPPED).start_number);

    return 0;
}

competitor_t winners(competitor_t* competitor,int size_of_array, category_t category)
{
    int min_time = UINT_MAX;
    int index = 0;
    //size_of_array = (int) malloc(size_of_array * sizeof(int));
    for (int i = 0; i < size_of_array; ++i) {
        if (competitor[i].category == category) {
            //for (int j = 0; j < category; ++j) {
            if (competitor[i].finish_time < min_time) {
                min_time = competitor[i].finish_time;
                index = i;
            }
        }
    }
    return competitor[index];
}

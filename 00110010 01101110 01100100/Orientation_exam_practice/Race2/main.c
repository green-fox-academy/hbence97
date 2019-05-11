#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef enum {
    HANDICAPPED,
    AMATEUR,
    PROFESSIONAL
} category_e;

typedef struct {
    unsigned int start_number;
    category_e category;
    unsigned int finish_time;
} competitor_t;

competitor_t winner(competitor_t *competitor, int size_of_array, category_e category)
{
    int min_time = UINT_MAX;
    int index = 0;

    for (int i = 0; i < size_of_array; ++i) {
        if(competitor[i].category == category){
            if (competitor[i].finish_time < min_time){
                min_time = competitor[i].finish_time;
                index = i;
            }
        }
    }
    return competitor[index];
}

int main() {

    srand(time(NULL));

    int num_of_competitors = rand() % 100 + 30;
    competitor_t competitors[num_of_competitors];
    for (int i = 0; i < num_of_competitors; ++i) {
        competitors[i].start_number = i + 1;
        competitors[i].category = rand() % 3;
        competitors[i].finish_time = rand() % 2500 + 3000;
    }
    int competitors_length = sizeof(competitors) / sizeof(*competitors);

    printf("There are %d competitors\n", competitors_length);
    printf("The winner in amateur category is the competitor nr. %d.\n", winner(competitors,num_of_competitors,AMATEUR).start_number);
    printf("The winner in professional category is the competitor nr. %d.\n", winner(competitors,num_of_competitors,PROFESSIONAL).start_number);
    printf("The winner in handicapped category is the competitor nr. %d.\n", winner(competitors,num_of_competitors,HANDICAPPED).start_number);

    return 0;
}
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

typedef enum category {
    HANDICAPPED,
    AMATEUR,
    PROFESSIONAL
} category_t;

typedef struct competitor {
    unsigned int start_number;
    category_t category;
    unsigned int finish_time;
} competitor_t;

competitor_t winners(competitor_t *competitors, int array_length, category_t ctgry) {
    int min_time = UINT_MAX;
    int index = 0;
    for (int i = 0; i < array_length; ++i) {
        if (competitors[i].category == ctgry) {
            if (competitors[i].finish_time < min_time) {
                min_time = competitors[i].finish_time;
                index = i;
            }
        }
    }
    return competitors[index];
}

int main() {
    srand(time(NULL));
    int competitor_size = rand() % 30 + 30;
    competitor_t competitors[competitor_size];
    for (int i = 0; i < competitor_size; i++){
        competitors[i].start_number = i + 1;
        competitors[i].category = rand() % 3;
        competitors[i].finish_time = rand() % 2500 + 3000;
    }
    int competitors_length = sizeof(competitors) / sizeof(*competitors);
    printf("There are %d competitors\n", competitors_length);
    printf("And the winner in the Amateur category is: %d\n", winners(competitors, 5, AMATEUR).start_number);
    printf("And the winner in the Professional category is: %d\n", winners(competitors, 5, PROFESSIONAL).start_number);
    printf("And the winner in the handicapped category is: %d\n", winners(competitors, 5, HANDICAPPED).start_number);
    //free(aPTR);
    return 0;
}
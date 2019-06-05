#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int marks;
    char subject[30];
} results_t;

int main() {
    int i = 0;
    results_t *ptr;
    int number_of_records;
    printf("Enter the number of records.\n");
    scanf("%d", &number_of_records);
    ptr = (results_t*) malloc (number_of_records * sizeof(results_t));
    
    for (i = 0; i < number_of_records; ++i) {
        printf("Enter the subjects and the marks respectively.\n");
        scanf("%s %d", &(ptr + i)->subject, &(ptr + i)->marks);
    }
    printf("Let's display the informations!\n");

    for (i = 0; i < number_of_records; ++i) {
        printf("%s %d\n", (ptr + i)->subject, (ptr + i)->marks);
    }
    free(ptr);
    return 0;
}
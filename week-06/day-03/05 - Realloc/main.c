#include <stdio.h>
#include <stdlib.h>

// Prompt the user to enter a number. -> This number will be X.
// Allocate memory for X numbers.
// Prompt the user to enter X numbers.
// Allocate memory for Y numbers, which is the sum of the X numbers.0
// Fill that array with from 1 to Y, then print them.

int main()
{
    int* pointer = NULL;
    printf("How many numbers do you want to enter:\n");
    int x = 0;
    scanf("%d", &x);
    pointer = (int *) malloc(x * sizeof(int));
    for (int i = 0; i < x; ++i) {
        printf("Now give me the numbers! %d \n", i + 1);
        scanf("%d", &pointer[i]);
    }
    int y = 0;
    for (int i = 0; i < x; ++i) {
        y += pointer[i];
    }

    realloc(pointer, y * sizeof(pointer));

    for (int j = 0; j < y; ++j) {

    }

    return 0;
}
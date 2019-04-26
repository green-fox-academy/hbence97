#include <stdio.h>
#include <stdlib.h>

// please allocate a 10 long array and fill it with even numbers
// please allocate a 10 long array and fill it with odd numbers
// select an array, and push the elements into the another array
// print the array in descending order
// delete the arrays after you don't use them

int main()
{
    int* pointer = NULL;
    pointer = (int *) malloc(10 * sizeof(int));
    for (int i = 0; i < 10; ++i) {
        pointer[i] = i * 2;
        printf("%d\n",pointer[i]);
    }
    int* pointer2 = NULL;
    pointer2 = (int *) malloc(10 * sizeof(int));
    for (int j = 0; j < 10; ++j) {
        pointer2[j] = (j * 2) + 1;
        //printf("%d\n", pointer2[j]);
    }
    pointer = (int *) realloc(pointer, 20 * sizeof(int));
    for (int k = 0; k < 20; ++k) {
        pointer[k] = k;
        printf("%d", pointer[k]);
    }

    return 0;
}
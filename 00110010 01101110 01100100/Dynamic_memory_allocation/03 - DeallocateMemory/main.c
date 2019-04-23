#include <stdio.h>
#include <stdlib.h>

// with malloc
// please allocate a 10 long array and fill it with even numbers then print the whole array
// please deallocate memory without using free


int main()
{
    int* pointer = NULL;
    pointer = (int *) malloc(10 * sizeof(int));
    for (int i = 0; i < 10; ++i) {
        pointer[i] = i * 2;
        printf("%d\n",pointer[i]);
    }
    realloc(pointer, 0);
    return 0;
}
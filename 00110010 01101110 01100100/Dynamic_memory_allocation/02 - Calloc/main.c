#include <stdio.h>
#include <stdlib.h>

// with calloc
// please allocate a 10 long array and fill it with 5!! numbers from 0 to 4, then print the whole array
// please delete the array before the program exits
// what's the difference between this and the previous excersice?

int main()
{
    int* pointer = NULL;
    pointer = (int *) calloc(10, sizeof(int));
    for (int i = 0; i < 10; ++i) {
        if(i < 5){
            pointer[i] = i;
        } else {
            pointer[i] = i - 5;
        }
        printf("%d\n",pointer[i]);
    }
    free(pointer);
    //The difference is that with calloc, we inicialized all the elements of the memory block to 0!
    return 0;
}
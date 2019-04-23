#include <stdio.h>
#include <stdlib.h>

int main() {

    int *num_array;
    // malloc() allocate the memory for 5 integers containing garbage values
    num_array = (int *) malloc(5 * sizeof(int));
    // deallocate memory
    free(num_array);

    // calloc() allocate the memory for 5 integers and set 0 to all of them
    num_array = (int *) calloc(5, sizeof(int));
    // deallocate memory
    free(num_array);

    return 0;
}
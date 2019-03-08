#include <stdio.h>
#include <stdlib.h>

// please allocate a 10 long array and fill it with even numbers
// please allocate a 10 long array and fill it with odd numbers
// select an array, and push the elements into the another array
// print the array in descending order
// delete the arrays after you don't use them

int cpmfunc(const void *a, const void *b)
{
    return (*(int*)a - *(int*) b);
}

int main()
{
    int* even = NULL;
    const int size_of_array = 10;
    even = (int*) malloc(size_of_array * sizeof(int));

    for (int i = 0; i < size_of_array; ++i) {
        even[i] = (i + 1) * 2;
        printf("The nr: %d element is %d\n", i + 1, even[i]);
    }

    printf("\n");

    int* odd = NULL;
    const int size_of_array2 = 10;
    odd = (int*) malloc(size_of_array2 * sizeof(int));

    for (int j = 0; j < size_of_array2; ++j) {
        odd[j] = (j + 1) * 2 - 1;
        printf("The nr: %d element is %d\n", j+1, odd[j]);
    }

    int* result_pointer = NULL;
    int length_of_result_pointer = (size_of_array + size_of_array2);
    result_pointer = (int*) malloc(length_of_result_pointer * sizeof(int));

    for (int k = 0; k < result_pointer; ++k) {
        if (k < 10){
            result_pointer[k] = even[k];
        } else {
            result_pointer[k] = odd[k - 10];
        }
    }

    qsort(result_pointer, 20, sizeof(int), cpmfunc);
    int temp = 0;
    
    return 0;
}
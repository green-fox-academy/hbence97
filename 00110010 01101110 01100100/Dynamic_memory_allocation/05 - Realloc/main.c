#include <stdio.h>
#include <stdlib.h>

// Prompt the user to enter a number. -> This number will be X.
// Allocate memory for X numbers.
// Prompt the user to enter X numbers.
// Allocate memory for Y numbers, which is the sum of the X numbers.
// Fill that array with from 1 to Y, then print them.

int main()
{
    int x = 0;
    int y = 0;

    printf("Enter a number.\n");
    scanf("%d",&x);

    int* pointer = (int*) malloc(x * sizeof(int));

    printf("Now tell me %d numbers.\n", x);
    for (int i = 0; i < x; ++i) {
        scanf("%d",&pointer[i]);
        y += pointer[i];
    }
    int* pointer2 = (int*)malloc(y * sizeof(int));
    for (int j = 0; j < y; ++j) {
        pointer2[j] = j + 1;
        printf("%d\n",pointer2[j]);
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Prompt the user to enter a number. -> This number will be X.
// Allocate memory for X numbers.
// Prompt the user to enter X numbers.
// Allocate memory for Y numbers, which is the sum of the X numbers.0
// Fill that array with from 1 to Y, then print them.

int main()
{
    int user_input;
    printf("how many numbers will you want to enter?\n");
    scanf("%d", &user_input);

    int* user_numbers=(int*)malloc(user_input*sizeof(int));

    printf("space reserved, you're safe to enter them, sir!\n");
    int sum=0;
    for(int i=0; i<user_input; i++){
        scanf("%d", &user_numbers[i]);
        sum+=user_numbers[i];
    }

    int* sum_arr=(int*)malloc(sum*sizeof(int));
    for(int i=0; i<sum; i++){
        sum_arr[i]=i+1;
        printf("%d ", sum_arr[i]);
    }

    free(user_numbers);
    free(sum_arr);

    return 0;
}
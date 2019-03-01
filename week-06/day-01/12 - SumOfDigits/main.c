#include <stdio.h>
#include <stdlib.h>

int sum(int testNum1, int testNum2);

int main()
{
    // Create a program which asks for two numbers and stores them
    // Create a function which takes two numbers as parameters
    // and returns 1 if the sum of the number of digits are equal and 0 otherwise
    //
    // For example:
    //
    // Case 1:
    //
    // a = 123
    // b = 321
    //
    // sum of number of digits (variable a) = 1 + 2 + 3 = 6
    // sum of number of digits (variable b) = 3 + 2 + 1 = 6
    // in this case the function should return 1
    //
    //
    // Case 2:
    //
    // a = 723
    // b = 114
    //
    // sum of number of digits (variable a) = 7 + 2 + 3 = 12
    // sum of number of digits (variable b) = 1 + 1 + 4 = 6
    // in this case the function should return 0

    printf("Tell me 2 numbers and I'll tell you if the sum of the 2 number's digits are equal\n");
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    printf("%d\n",sum(a,b));

    return 0;
}

int sum(int testNum1, int testNum2)
{
    int sum1 = 0;
    int sum2 = 0;

    while (testNum1 > 0){
        sum1 += testNum1 % 10;
        testNum1 /= 10;
    }

    while (testNum2 > 0){
        sum2 += testNum2 % 10;
        testNum2 /= 10;
    }
    if(sum1 == sum2) {
        return 1;
    } else {
        return 0;
    }
}
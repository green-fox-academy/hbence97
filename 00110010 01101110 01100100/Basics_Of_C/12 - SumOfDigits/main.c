#include <stdio.h>
#include <stdlib.h>

int sum_of_digits(int number1, int number2)
{
    int sum1 = 0;
    int sum2 = 0;
    while (number1 != 0){
        sum1 = sum1 + number1 % 10;
        number1 = number1 / 10;
    }
    while (number2 != 0){
        sum2 = sum2 + number2 % 10;
        number2 = number2 / 10;
    }
    if(sum1 == sum2){
        return 1;
    } else {
        return 0;
    }
}

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
    int a;
    int b;

    printf("Tell me a number\n");
    scanf("%d", &a);
    printf("And another one\n");
    scanf("%d", &b);

    printf("%d", sum_of_digits(a, b));
    return 0;
}
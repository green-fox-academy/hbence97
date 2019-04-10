#include<stdio.h>

int main()
{
    // Create a program that prints a few operations on two numbers: 22 and 13
    int a = 22;
    int b = 13;
    // Print the result of 13 added to 22
    int sum = a + b;
    // Print the result of 13 substracted from 22
    int substract = a - b;
    // Print the result of 22 multiplied by 13
    int multiple = a * b;
    // Print the result of 22 divided by 13 (as a decimal fraction)
    float divide = (float) b / (float) a;
    // Print the reminder of 22 divided by 13
    int remainder = b & a;
    // Store the results in variables and use them when you display the result
    printf("%d\n", sum);
    printf("%d\n", substract);
    printf("%d\n", multiple);
    printf("%.2f\n", divide);
    printf("%d\n", remainder);

    return 0;
}
#include<stdio.h>

int main()
{
    // Create a program that prints a few operations on two numbers: 22 and 13
    int a = 22;
    int b = 13;

    // Print the result of 13 added to 22+
    int c = 13 + 22;
    printf("13 + 22 = %d\n", c);
    // Print the result of 13 substracted from 22
    int d = 22 - 13;
    printf("22 - 13 = %d\n", d);
    // Print the result of 22 multiplied by 13
    int e = 22 * 13;
    printf("22 * 13 = %d\n", e);
    // Print the result of 22 divided by 13 (as a decimal fraction)
    float f = (float) 22 / (float) 13;
    printf("22 / 13 = %f\n", f);
    // Print the reminder of 22 divided by 13
    int g = 22 % 13;
    printf("22 % 13 = %d", g);
    // Store the results in variables and use them when you display the result

    return 0;
}
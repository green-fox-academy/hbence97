#include <stdio.h>
#include <stdlib.h>

int numbers(int num1, int num2)
{
    if(num1 == num2){
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    // Create a program which asks for two integers and stores them separatly
    // Create a function which takes two numbers as parameters and
    // returns 1 if they are equal and returns 0 otherwise

    int number1;
    int number2;
    printf("Tell me a number\n");
    scanf("%d", &number1);
    printf("Now tell me another one\n");
    scanf("%d", &number2);
    printf("%d", numbers(number1,number2));

    return 0;
}
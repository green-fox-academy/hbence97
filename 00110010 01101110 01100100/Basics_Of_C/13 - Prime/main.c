#include <stdio.h>
#include <stdlib.h>

int prime(int number)
{
    int i;
    for (i = 2; i <= number - 1 ; ++i) {
        if (number % i == 0)
        return 0;
    }
    if(i == number) {
        return 1;
    }
}

int main()
{
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter
    // and returns 1 if the number is a prime number and 0 otherwise
    // (in this case 0 is not considered as a prime number)
    int num;
    printf("Tell me a number, and I'll tell you if it's a prime number or not.\n");
    scanf("%d",&num);
    printf("%d", prime(num));
    return 0;
}
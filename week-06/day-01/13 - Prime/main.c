#include <stdio.h>
#include <stdlib.h>

int prime(int a);

int main()
{
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter
    // and returns 1 if the number is a prime number and 0 otherwise
    // (in this case 0 is not considered as a prime number)
    printf("Give me a number and I'll tell you if it's a prime number or not.\n");
    int b;
    scanf("%d", &b);
    printf(prime(b));

    return 0;
}

int prime(int a)
{
    int primeNumber;
    primeNumber = a;
    if(primeNumber % a == 0 && primeNumber / 1 == a){
        return 1;
    } else {
        return 0;
    }
}
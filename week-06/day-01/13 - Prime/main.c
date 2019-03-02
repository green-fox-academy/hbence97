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
    int a;
    scanf("%d", &a);
    printf("Your number is %d\n", prime(a));
    return 0;
}

int prime(int a)
{
    int b = 1;
    if(a > 1){
        for (int i = 2; i <= a / 2 ; ++i) {
            if (a % i == 0) {
                b = 0;
            }
        }
    }
    return b;
}
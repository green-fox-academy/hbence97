#include <stdio.h>
#include <stdlib.h>

int number(int a);

int main()
{
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter and
    // returns 1 if that number is even and returns 0 otherwise
    // (in this case 0 is an even number)
    int a;
    printf("Tell me a number and I'll tell you it it's even or odd.\n");
    scanf("%d",&a);
    printf(number(a));

    return 0;
}

int number(int a)
{
    if (a % 2 == 0 || 0) {
        return "Your number is even.";
    } else {
        return "Your number is odd.";
    }
}

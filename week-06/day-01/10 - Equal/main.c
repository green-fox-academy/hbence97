#include <stdio.h>
#include <stdlib.h>

int Numbers(int a, int b);

int main()
{
    // Create a program which asks for two integers and stores them separatly
    // Create a function which takes two numbers as parameters and
    // returns 1 if they are equal and returns 0 otherwise
    int a;
    int b;
    printf("Tell me a number\n");
    scanf("%d", &a);
    printf("And another one\n");
    scanf("%d", &b);

    printf(Numbers(a, b));

    return 0;
}

int Numbers(int a, int b)
{
    if(a == b) {
        return "1";
    } else {
        return "0";
    }
}
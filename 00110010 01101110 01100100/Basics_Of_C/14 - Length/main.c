#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int length(char* string)
{
    return strlen(string);
}

int main()
{
    // Create a program which asks for the name of the user and stores it
    // Create a function which takes a string as a parameter and returns the lenght of it
    // Solve this exercie with and without using string.h functions

    char name [100];
    printf("Tell me your name\n");
    scanf("%s", &name);
    printf("Your name is %d character long\n", length(name));

    return 0;
}
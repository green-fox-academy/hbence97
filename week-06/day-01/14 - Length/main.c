#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculateLength(char* name);

int main()
{
    // Create a program which asks for the name of the user and stroes it
    // Create a function which takes a string as a parameter and returns the lenght of it
    // Solve this exercie with and without using string.h functions

    char name[20];
    printf("What's your name?\n");
    scanf("%s", name);
    printf("%d", calculateLength(name));

    return 0;
}

int calculateLength (char* name)
{
    return strlen(name);
}
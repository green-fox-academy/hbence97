#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int areTheSame(char* string1, char* string2);

main()
{
    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the two strings are the same and 0 otherwise
    // Try to erase small and uppercase sensitivity.
    char string1 [20];
    char string2 [20];
    printf("Give me a word\n");
    scanf("%s", string1);
    printf("And another one\n");
    scanf("%s", string2);
    printf("%d", areTheSame(string1,string2));
    return 0;
}

int areTheSame(char* string1, char* string2)
{
    if (strcmp(string1, string2) == 0){
        return 1;
    } else {
        return 0;
    }
}
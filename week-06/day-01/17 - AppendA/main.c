#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* word(char* string);

int main()
{
    // Create a program which asks for a string and stores it
    // Create a function which takes a string as a parameter and
    // appends a character 'a' to the end of it and returns the new string
    char str[100];
    printf("Tell me a word.\n");
    scanf("%s",str);

    printf("The new word is: %s",word(str));
    return 0;
}

char * word(char * string)
{
    const char string2 = 'a';

    strcat(string, &string2);

    return string;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// write a function which takes 2 strings as parameter, concatenates them together and returns it back.
// Test it for long and empty strings as well.
// Try to use the least amount of memory that's possible.

char* concatenates (const char* string1, const char* string2)
{
    char* strings = malloc(strlen(string1) + strlen(string2) + 1);
    strcpy(strings, string1);
    strcat(strings, string2);
    return strings;
}


int main()
{
    char* s1 = "Thank";
    char* s2 = " you";
    char* s = concatenates(s1,s2);
    printf("%s",s);

    free(s);
    return 0;
}
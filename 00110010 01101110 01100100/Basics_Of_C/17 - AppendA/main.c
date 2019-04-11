#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* append_a(char* string)
{
    const char character = 'a';
    strcat(string, &character);
    return string;
}

int main()
{
    // Create a program which asks for a string and stores it
    // Create a function which takes a string as a parameter and
    // appends a character 'a' to the end of it and returns the new string

    char user_string[100];
    printf("Give me a word\n");
    scanf("%s", user_string);
    printf("%s",append_a(user_string));

    return 0;
}
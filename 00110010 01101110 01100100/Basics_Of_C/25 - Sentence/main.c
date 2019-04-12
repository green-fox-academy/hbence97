#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter,
// and splits a string to words by space
// solve the problem with the proper string.h function

char* spaces(char* array)
{
    for (char *p = strtok(array, " "); p != NULL; p = strtok(NULL, " ")) {
        puts(p);
    }
}


int main()
{
    printf("Type in a sentence:\n");
    char string[256];
    gets(string);
    printf("%s", spaces(string));

    return(0);
}
#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter and
// returns the distance between the first and last occurance of character 's'

int between_char(char* string, char c)
{
    char* word;
    char* word2;
    word = strchr(string,c);
    word2 = strrchr(string,c);
    return word2 - word - 1;
}

int main ()
{
    char str[] = "This is a sample string";

    printf("%d", between_char(str,'s'));

    return 0;
}
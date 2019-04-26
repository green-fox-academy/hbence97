#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// write a function which takes a string and an integer as a parameter.
// The function should return a string where the input string is repeating. The number of repetition is based on the value of the integer parameter.
// For example: Apple, 5 -> AppleAppleAppleAppleApple
// Try to use the least amount of memory that's possible.

char* repeat(char* string, int number_of_times)
{
    char* repeated;
    repeated = (char*) malloc(number_of_times * (sizeof(char)));
    for (int i = 0; i < number_of_times; ++i) {
        strcat(repeated, string);
    }
    return repeated;
}

int main()
{
    char* s = repeat("Thankful ", 5);
    printf("%s", s);

    free(s);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_substring(char* string1, char* string2)
{
    if(strstr(string1,string2) != NULL){
        return 1;
    } else if(strlen(string1) == strlen(string2)){
        return -1;
    } else {
        return 0;
    }
}

int main()
{
    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the shorter string is a substring of the longer one and
    // returns 0 otherwise
    // If the two strings has the same lenght than the function should return -1

    char* a = "This is a test";
    char* b = "test";

    printf("%d", is_substring(a, b));

    return 0;
}
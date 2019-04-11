#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(char string1[], char string2[])
{
    if(strcmp(string1,string2) == 0){
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the two strings are the same and 0 otherwise
    // Try to erase small and uppercase sensitivity.

    char str1[100];
    char str2[100];

    printf("Tell me a string\n");
    scanf("%s", str1);
    printf("And another one\n");
    scanf("%s", str2);
    printf("%d",compare(str1,str2));

    return 0;
}
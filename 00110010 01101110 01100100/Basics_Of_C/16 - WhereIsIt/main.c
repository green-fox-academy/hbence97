#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int appearance(char* string, char c)
{
    int index;
    char* ret;
    ret = strchr(string,c);
    if(ret == NULL){
        return -1;
    } else {
        index = ret - string;
        return index / sizeof(char);
    }
}

int main()
{
    // Create a program which asks for a string and a character and stores them
    // Create a function which takes a string and a character as a parameter and
    // if the given character is in the string, it should return the index of the
    // first appearance (in the given string) otherwise the function should return -1
    //
    // Example:
    //
    // Case 1:
    //
    // given_string = "embedded"
    // given_char = 'd'
    //
    // the function should return: 4, because this is the index of the first appearance of char 'd'
    //
    //
    // Case 2:
    //
    // given_string = "embedded"
    // given_char = 'a'
    //
    // the function should return: -1, because there is no 'a' in the word "embedded"
    //
    char character;
    char sentence [100];

    printf("Give me a sentence\n");
    gets(sentence);
    printf("And now give me a character\n");
    scanf("%c", &character);
    printf("%d", appearance(sentence, character));

    return 0;
}
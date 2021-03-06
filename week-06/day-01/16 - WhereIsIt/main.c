#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int letterFinder(char* testSentence, char character);

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

    puts("Give me a sentence");
    char sentence[50];
    gets(sentence);
    printf("And now a character\n");
    char letter;
    scanf("%c",&letter);

    printf("%d", letterFinder(sentence,letter));


    return 0;
}

int letterFinder(char* testSentence, char character)
{
    int index;
    char* pointer;
    //char* strchr (const char *, int);
    pointer = strchr (testSentence, character);
    if (pointer == NULL){
        return -1;
    } else {
        index = pointer - testSentence;
        return index / sizeof(char);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_in_sentence(char* wrd,char* sntnce)
{
    char* result = strstr(sntnce, wrd);
    int position = result - sntnce;
    if(strstr(sntnce,wrd) != NULL){
        return position;
    } else {
        return 0;
    }
}

int main()
{
    // Create a function which takes two strings as parameters
    // One string is actually a sentence and the other one is a word
    // It should return the index of the word in the sentence and 0 otherwise
    // Try to erase small and uppercase sensitivity.

    char *word = "doctor";
    char *sentence = "An apple a day keeps the doctor away.";

    // the output should be: 6
    printf("%d",is_in_sentence(word, sentence));

    return 0;
}
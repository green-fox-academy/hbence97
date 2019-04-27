#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{
    VOWEL_HEAVY,
    CONSONANT_HEAVY,
    BALANCED
} classifier_t;

classifier_t get_classifier(char* string)
{
    int vowel_counter = 0;
    int consonant_counter = 0;
    int i = 0;
    while (string[i] != '\0')
    {
        if(string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u' ||
           string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U')
        {
            vowel_counter++;
        } else {
            consonant_counter++;
        }
        i++;
    }
    if (vowel_counter > consonant_counter){
        return VOWEL_HEAVY;
    }
    if (consonant_counter > vowel_counter){
        return CONSONANT_HEAVY;
    }
    if (consonant_counter == vowel_counter){
        return BALANCED;
    }
}

void print_sentence (classifier_t classifier){
    if (classifier == VOWEL_HEAVY){
        printf("The sentence is vowel heavy.\n");
    }
    if (classifier == CONSONANT_HEAVY){
        printf("The sentence is consonant heavy.\n");
    }
    if (classifier == BALANCED){
        printf("The sentence is balanced.\n");
    }
}

int main() {

    char* sentence = "eeefff";

    classifier_t classifier = get_classifier(sentence);
    print_sentence(classifier);

    return 0;
}
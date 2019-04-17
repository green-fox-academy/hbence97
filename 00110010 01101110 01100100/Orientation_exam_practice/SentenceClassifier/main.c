#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    VOWEL_HEAVY,
    CONSONANT_HEAVY,
    BALANCED
} classifier_t;

classifier_t classifier(const char* sntnc)
{
    int i = -1;
    int vowels = 0;
    int consonants = 0;
    //printf("Enter a sentence.\n");
    //gets(str);

    while(sntnc[i] != '\0'){
        if(sntnc[i] == 'a' || sntnc[i] == 'e' || sntnc[i] == 'i' || sntnc[i] == 'o' || sntnc[i] == 'u' ||
           sntnc[i] == 'A' || sntnc[i] == 'E' || sntnc[i] == 'I' || sntnc[i] == 'O' || sntnc[i] == 'U')
        {
            vowels++;
        } else {
            consonants++;
        }
        i++;
    }


    if(vowels > consonants) {
        return VOWEL_HEAVY;
    } else if (consonants > vowels) {
        return CONSONANT_HEAVY;
    } else {
        return BALANCED;
    }
}

void print(classifier_t sentence)
{
    if (sentence == CONSONANT_HEAVY) {
        printf("The sentence is consonant heavy");
    }
    if (sentence == VOWEL_HEAVY) {
        printf("The sentence is vowel heavy");
    }
    if (sentence == BALANCED) {
        printf("The sentence is balanced");
    }
}

int main() {

    char str[100];
    fgets(str,100,stdin);

    classifier_t sentence = classifier(str);
    print(sentence);
    return 0;
}
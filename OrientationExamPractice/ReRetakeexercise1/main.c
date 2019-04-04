#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    VOWEL_HEAVY ,
    CONSONANT_HEAVY ,
    BALANCED
} classifier_t;

classifier_t get_sentence_classifier(const char *sentence)
{
    int vowel_count = 0;
    int consonant_count = 0;

    for (int i = 0; i < strlen(sentence); ++i) {
        char c = tolower(sentence[i]);
        if(isalpha(c)) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                vowel_count++;
            } else {
                consonant_count++;
            }
        }
    }
    if (vowel_count > consonant_count){
        return VOWEL_HEAVY;
    } else if (vowel_count < consonant_count) {
        return CONSONANT_HEAVY;
    } else {
        return BALANCED;
    }
}

void print_sentence_classifier(classifier_t classifier)
{
    if (classifier == VOWEL_HEAVY){
        printf("The sentence is vowel heavy!\n");
    }
    if (classifier == CONSONANT_HEAVY){
        printf("The sentence is consonant heavy!\n");
    }
    if (classifier == BALANCED){
        printf("The sentence is balanced!\n");
    }
}

int main() {
    char sentence[100];
    fgets(sentence,100,stdin);

    classifier_t classifier = get_sentence_classifier(sentence);
    print_sentence_classifier(classifier);

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int vowel_counter(char *file_name, char *new_file)
{
    FILE *input_file = fopen(file_name, "r");
    FILE *input_file2 = fopen(new_file, "w");

    if (input_file == NULL) {
        printf("Error occured!");
        return -1;
    }
    if (new_file == NULL) {
        printf("Error occured!");
        return -1;
    }
    int counter = 0;

    char* vowels = (char*) calloc(2, sizeof(char));

    int ch;
    while(!feof(input_file)) {
        ch = fgetc(input_file);
        if (ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u'
        || ch == 'A' || ch == 'E' || ch == 'O' ||  ch == 'I' || ch == 'U'){
            vowels[counter] = ch;
            vowels [counter + 1] = '\0';
            counter++;
            vowels = realloc(vowels, sizeof(char) * counter + 2);
        }
    }
    fputs(vowels, input_file2);
    fclose(input_file);
    fclose(input_file2);
    return counter;
}

int main() {
    int vowel_count = vowel_counter("../../input.txt","../../just_some_vowels.txt");
    printf("%d", vowel_count);
    return 0;
}
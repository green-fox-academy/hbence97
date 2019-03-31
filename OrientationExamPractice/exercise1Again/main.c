#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int vowel_counter(char* old_file, char* new_file)
{
    FILE *input_file = fopen(old_file, "r");
    FILE *output_file= fopen(new_file, "w");

    if (input_file == NULL){
        printf("Error!\n");
        return -1;
    }
    if (output_file == NULL){
        printf("Error!\n");
        return -1;
    }
    int counter = 0;

    char* vowels = (char*) calloc(2, sizeof(char));

    int ch;
    while(!feof(input_file)) {
        ch = fgetc(input_file);
        if (ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u'
        || ch == 'A' || ch == 'E' || ch == 'O' ||  ch == 'I' || ch == 'U') {
            vowels[counter] = ch;
            vowels [counter + 1] = '\0';
            counter++;
            vowels = realloc(vowels, sizeof(char) * counter + 2);
        }
    }
    fputs(vowels, output_file);
    fclose(input_file);
    fclose(output_file);
    return counter;
}

int main()
{
    int vowel_count = vowel_counter("../../input.txt","../../just_some_vowels2.txt");
    printf("%d", vowel_count);
    return 0;
}
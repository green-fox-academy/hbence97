#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void replace_all_characters(char* string, char* old_word, char* new_word);

int main() {

    FILE *fp;
    FILE *fp_temporary;

    char buffer[150];
    char old_word[150];
    char new_word[150];

    printf("Enter what word you want to replace.\n");
    scanf("%s", old_word);
    printf("Replace with: \n");
    scanf("%s", new_word);

    fp = fopen("original_text.txt", "r");
    fp_temporary = fopen("new_text.txt", "w");

    if (fp == NULL || fp_temporary == NULL){
        printf("There was an error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    // Read line from source file and write to destination file after replacing the given word
    while ((fgets(buffer, 150, fp)) != NULL){
        // Replace all occurence of word from the current line
        replace_all_characters(buffer, old_word, new_word);
        // After replacing, write it into the temporary file
        fputs(buffer, fp_temporary);
    }
    fclose(fp);
    fclose(fp_temporary);
    // Delete original source file
    remove("original_text.txt");
    // Rename temporary file as original file
    rename("new_text.txt", "original_text.txt");

    return 0;
}

void replace_all_characters(char* string, char* old_word, char* new_word)
{
    char* position;
    char temporary[150];
    int index = 0;
    int old_word_length;

    old_word_length = strlen(old_word);

    while ((position = strstr(string, old_word)) != NULL){

        strcpy(temporary,string);
        // Index of current found word
        index = position - string;
        // Terminating the string after word found index
        string[index] = '\0';
        // Concatenate string with the new word
        strcat(string,new_word);
        // Concatenate str with remaining words after old word found index
        strcat(string,temporary + index + old_word_length);
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void counting_in_a_file(char* file);

int main() {

    counting_in_a_file("text.txt");
    return 0;
}

void counting_in_a_file(char* file)
{
    FILE *fp;
    fp = fopen(file, "r");
    if (fp == NULL){
        printf("There was an error opening the file.\n");
        exit(EXIT_FAILURE);
    }

    int characters = 0;
    int words = 0;
    int lines = 0;

    char ch;
    while ((ch = fgetc(fp)) != EOF){
        characters++;
        if(ch == '\n' || ch == '\0') {
            lines++;
        }
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0'){
            words++;
        }
    }
    if (characters > 0) {
        words++;
        lines++;
    }
    printf("Total characters: %d\n", characters);
    printf("Total words: %d\n", words);
    printf("Total lines: %d\n", lines);

    fclose(fp);
}
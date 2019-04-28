#include <stdio.h>
#include <string.h>

// Create a function that takes 3 parameters: a path, a word and a number
// and is able to write into a file.
// The path parameter should be a string that describes the location of the file you wish to modify
// The word parameter should also be a string that will be written to the file as individual lines
// The number parameter should describe how many lines the file should have.
// If the word is "apple" and the number is 5, it should write 5 lines
// into the file and each line should read "apple"

char* write_multiple_lines(char* file_name, char* word, int number)
{
    FILE *fptr;
    fptr = fopen(file_name, "w");

    for (int i = 0; i < number; ++i) {
        fprintf(fptr,"%s\n", word);
    }
    fclose(fptr);

    fptr = fopen(file_name, "r");
    char line[100];
    while(!feof(fptr)) {
        fgets(line, 100, fptr);
        puts(line);
    }
}

int main()
{
    printf("%s",write_multiple_lines("my-file.txt", "Platinum", 4));

    return 0;
}
#include <stdio.h>
#include <string.h>

// Write a function that takes a filename as string,
// then returns the number of lines the file contains.
// It should return zero if it can't open the file

int lines (char* file_name)
{
    FILE *fptr;
    fptr = fopen(file_name,"r");
    int ch = 0;
    int line = 0;

    if (fptr == NULL){
        return 0;
    }

    while (!feof(fptr)){
        ch = fgetc(fptr);
        if (ch == '\n') {
            line++;
        }
    }
    return line;
}

int main ()
{
    printf("There are %d lines in the file.\n", lines("my-file.txt.") + 1);
    return 0;
}
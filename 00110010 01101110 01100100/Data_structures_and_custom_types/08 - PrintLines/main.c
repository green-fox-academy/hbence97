#include <stdio.h>
#include <string.h>

// Write a program that opens a file called "my-file.txt", then prints
// each line from the file.
// You will have to create the file, for that you may use C-programming, although it is not mandatory

int main ()
{
    /*char string[100];
    FILE *fptr;
    fptr = fopen("my-file.txt", "a");

    printf("Write something into that file. \n");
    gets(string);
    fprintf(fptr,"\n%s\n", string);

    fclose(fptr);   Creating and writing to a file.
*/
    FILE *fptr;
    fptr = fopen("my-file.txt", "r");
    char in_the_file[150];

    while(!feof(fptr)){
        fgets(in_the_file,150, fptr);
        puts(in_the_file);
    }
    //Basically just creating a variable for a file, reading till the end of the file, and then putting whats in that file into that variable.

    return 0;
}
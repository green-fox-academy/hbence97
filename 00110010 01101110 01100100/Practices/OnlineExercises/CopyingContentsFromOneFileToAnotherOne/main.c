#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copying_from_one_file_to_another();

int main() {

    copying_from_one_file_to_another();
    return 0;
}

void copying_from_one_file_to_another()
{
    FILE *fp_read;
    fp_read = fopen("source.txt", "r");
    FILE *fp_write;
    fp_write = fopen("destination.txt", "w");
    if (fp_read == NULL || fp_write == NULL){
        printf("There was an error opening the file!\n");
        exit(EXIT_FAILURE);
    }
    char ch;

    ch = fgetc(fp_read);
    while (ch != EOF){
        fputc(ch,fp_write);
        ch = fgetc(fp_read);
    }
    fclose(fp_read);
    fclose(fp_write);
}

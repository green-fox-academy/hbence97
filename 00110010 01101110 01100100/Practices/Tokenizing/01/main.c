#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    FILE *fptr;
    fptr = fopen("tokenizing.txt", "r");
    char buffer[150];
    char* tokenizing;

    while (!feof(fptr)) {
        fgets(buffer,150,fptr);
        tokenizing = strtok(buffer, " - ");
        while(tokenizing != NULL) {
            printf("%s\n", tokenizing);
            tokenizing = strtok(NULL, " - ");
        }
    }
    return 0;
}
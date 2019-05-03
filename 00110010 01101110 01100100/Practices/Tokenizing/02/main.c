#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* tokenizing(char filename[])
{
    /*
    FILE *fp;
    fp = fopen(filename, "r");
    int number_of_lines = 0;
    char buffer[50];

    while (!feof(fp)){
        fgets(buffer, 50, fp);
        number_of_lines++;
    }
    fclose(fp);
    //Helyfoglaláshoz kéne a sorok száma
*/
    FILE *fp;
    fp = fopen(filename, "r");
    char buffer[50];
    char *name;
    while(!feof(fp)) {
        fgets(buffer, 50, fp);
        name = strtok(buffer, "-");
        while (name != NULL) {
            printf("%s\n", name);
            name = strtok(NULL, " -");
        }
    }
    fclose(fp);
}

int main() {

    printf("%s\n",tokenizing("../tokenizing.txt"));
    return 0;
}
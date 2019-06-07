#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int binary_to_ascii(char* binary_number);
char* read_file(char* filename);

int main() {

    char* text = binary_to_ascii("input.txt");

    printf("%s", text);


    return 0;
}

int binary_to_ascii(char* binary_number)
{
    int max_binary_number = 128;
    int ascii_num = 0;
    //01010111 = 0 * 128 + 1 * 64 + 0 * 32 + 1 * 16 + 0 * 8 + 1 * 4 + 1 * 2 + 1 * 1 = 87;
    while (*binary_number != '0') {
        if (*binary_number == '1') {
            ascii_num += max_binary_number;
        }
        max_binary_number /= 2;
        binary_number++;
    }
    return ascii_num;
}

char* read_file(char* filename)
{
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("There was an error opening the file.\n");
        return NULL;
    }

    char* result_string = (char*) malloc(sizeof(char));
    int index = 0;
    int i = 0;

    char binary_string[10];
    while (fgets(binary_string,10,fp)){
        if(binary_string[i] == ' '){
            binary_string[i - 1] = '\0';
        }
        char result = binary_to_ascii(binary_string);
        result_string [index] = result;
    }
    fclose(fp);
    free(result_string);

    return result_string;
}
#include <stdio.h>
#include <string.h>

int vowel_counter(char* file_name);

int main() {

    printf("%d",vowel_counter("input.txt"));

    return 0;
}

int vowel_counter(char* file_name)
{
    FILE *fp;
    fp = fopen(file_name,"r");
    if (fp == NULL){
        printf("There was an error opening the file.\n");
    }
    FILE *fp2;
    fp2 = fopen("just_some_vowels.txt", "w");
    if (fp2 == NULL){
        printf("There was an error opening the file.\n");
    }

    int counter = 0;
    char buffer;
    while(!feof(fp)){
        buffer = fgetc(fp);
        if((buffer =='a')||(buffer =='A')||(buffer=='e')||(buffer=='E')||(buffer=='i')||(buffer=='I')||(buffer=='o') ||(buffer=='O')||(buffer=='u')||(buffer=='U')) {
            counter++;
            fprintf(fp2,"%c",buffer);
        }
    }
    return counter;
}
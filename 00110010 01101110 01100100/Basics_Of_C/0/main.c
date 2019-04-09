#include <stdio.h>
#include <string.h>

//NO BOOL

int no_bool()
{
    int is_admin = 1;

    if(is_admin){
        printf("This is the true\n");
    } else {
        printf("This is the false\n");
    }
    return 0;
}

//strlen()

int characters_length()
{
    char name[20];

    printf("Hello, what's your name?\n");
    scanf("%s", name);

    printf("Wow, your name is %d characters long.\n", strlen(name));
    return 0;
}

//str copy, str append

int strcpy_strcat()
{
    char first[] = "This is a compl";
    char second[] = "ete sentence";

    char whole_sentence[100];
    strcpy(whole_sentence, first);
    printf("%s\n", whole_sentence);

    strcat(whole_sentence, second);
    printf("%s\n", whole_sentence);
    return 0;
}

//str comparing 2 strings

int strcmpare()
{
    char first[] = "This";
    char second[] = "That";

    if(strcmp(first, second) == 0){
        printf("The two string are the same\n");
    } else {
        printf("The two string are not the same\n");
    }
}

//tokenizing

int tokenizing()
{
    char sentence[] = "Welcome to the real world";

    for (char *p =strtok(sentence," "); p != NULL; p = strtok(NULL, " ")) {
        puts(p);
    }
}

int main() {

    //printf("%d",characters_length());
    //printf("%s",strcpy_strcat());
    //printf("%s",strcmpare());
    printf("%s", tokenizing());

    return 0;
}
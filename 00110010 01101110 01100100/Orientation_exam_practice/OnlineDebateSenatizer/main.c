#include <stdio.h>
#include <ctype.h>

char* senatizer (char* debate)
{
    gets(debate);
    int i = 1;
    char ch;
    char ch1;
    ch1 = debate[0];
    putchar(toupper(ch1));

    while (debate[i]) {
        ch = debate[i];
        putchar(tolower(ch));
        i++;
    }
}

int main() {

    printf("Write a comment.\n");
    char debate1[50];
    printf("%s", senatizer(debate1));

    return 0;
}
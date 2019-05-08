#include <stdio.h>
#include <ctype.h>
#include <string.h>

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

void removing_excl_mark(char* debate)
{
    gets(debate);
    int len;
    char excl = '!';

    len = strlen(debate);

    for (int i = 0; i < len; ++i)
    {
        if (debate[i] == excl)
        {
            for (int j = i; j < len; ++j)
            {
                debate[j] = debate[j + 1];
            }
            len--;
            i--;
        }
    }
}

int main() {

    char debate1[50];
    printf("Write a comment. I will remove the exclamation marks\n");
    removing_excl_mark(debate1);
    printf("%s\n",debate1);

    char debate2[50];
    printf("Write another one. Only the first letter will be capitalized.\n");
    printf("%s\n",senatizer(debate2));
    return 0;
}
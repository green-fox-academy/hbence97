#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter and
// lists all position where character 'i' is found

void pos(char* position)
{
    int index = 0;
    for (char *p = position; *p != '\0'; p++) {
        index++;
        if(*p == 'i'){
            printf("%d\n", index);
        }
    }
}

int main ()
{
    char string[55] = "This is a string for testing";
    pos(string);

    return 0;
}
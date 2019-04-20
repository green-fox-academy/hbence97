#include <stdio.h>
#include <string.h>

// Open a file called "my-file.txt"
// Write your name in it as a single line

int main ()
{
    FILE *fptr;
    fptr = fopen("my-file.txt","w");

    fprintf(fptr,"Hegyes Bence");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
    // Create a function which takes a string as a parameter and
    // returns the number of characters between two repeating characters
    // the repeating char can be a local variable in the function itself or
    // it can be passed to the function as parameter

    char *word = "Programming";

    // the output should be: 6 (in this case the repeating char was 'g')
    printf(count_between_chars(&word));

    return 0;
}
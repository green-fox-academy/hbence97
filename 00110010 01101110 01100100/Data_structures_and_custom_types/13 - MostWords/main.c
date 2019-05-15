#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS   1000

// Find the most common word in file.txt
// You need to make sure that characters like commas, colons, etc are not part of the words.
// Also make it case sensitive so words that only different in case sensitivity are the same.


int main() {
    FILE *fp;
    fp = fopen("text_file.txt", "r");
    if (fp == NULL) {
        printf("File not found.\n");
        exit(EXIT_FAILURE);
    }
    char words[MAX_WORDS][50];
    char word[50];
    int count[MAX_WORDS];
    int i;
    int len;
    int max_count = 0;

    for (i = 0; i< MAX_WORDS; i++) {
        count[i] = 0;
    }
    int index = 0;

    while(fscanf(fp,"%s", word) != EOF)
    {
        // Convert word to lowercase
        strlwr(word);

        // Remove last punctuation character
        len = strlen(word);
        if(ispunct(word[len - 1])) {
            word[len - 1] = '\0';
        }

        //Check if word exists in list of all distinct words
        max_count = 0;
        int is_unique = 1;
        for (i = 0; i < index && is_unique; ++i)
        {
            if(strcmp(words[i], word) == 0){
                is_unique = 0;
            }
        }
        // If word is unique then add it to distinct words list
        // and increment index. Otherwise increment occurrence
        // count of current word.
        if(is_unique)
        {
            strcpy(words[index], word);
            count[index]++;

            index++;
        } else {
            count[i - 1]++;
        }
    }
    fclose(fp);

    /*
     * Print occurrences of all words in file.
     */
    printf("\nOccurrences of all distinct words in file: \n");
    for (i=0; i<index; i++)
    {
        /*
         * %-15s prints string in 15 character width.
         * - is used to print string left align inside
         * 15 character width space.
         */
        printf("%-15s => %d\n", words[i], count[i]);
    }
    return 0;
}
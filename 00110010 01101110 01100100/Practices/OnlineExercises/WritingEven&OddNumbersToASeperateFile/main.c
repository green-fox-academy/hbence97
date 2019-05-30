#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reading_and_writing_to_a_file();

int main()
{
    reading_and_writing_to_a_file();
}

void reading_and_writing_to_a_file()
{
    FILE *fp_read;
    fp_read = fopen("numbers.txt", "r");
    FILE *fp_odd;
    fp_odd = fopen("odd.txt", "w");
    FILE *fp_even;
    fp_even = fopen("even.txt", "w");
    if (fp_even == NULL || fp_odd == NULL || fp_read == NULL){
        printf("There was an error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    int number_array[40];
    int i;
    int j;
    int odd_array[j];
    int even_array[j];

    for (i = 1; i <= 40; ++i) {
        fscanf(fp_read, "%d", &number_array[i]);
            if (number_array[i] % 2 != 0) {
                odd_array[j] = i;
                fprintf(fp_odd, "%d ", odd_array[j]);
            } else {
                even_array[j] = i;
                fprintf(fp_even, "%d ", even_array[j]);
            }
    }
    fclose(fp_read);
    fclose(fp_odd);
    fclose(fp_even);
}

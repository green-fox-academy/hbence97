#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    BETWEEN_15_AND_20,
    BETWEEN_20_AND_25,
    BETWEEN_25_AND_30,
    BETWEEN_30_AND_35,
    BETWEEN_35_AND_40
} age_groups;

typedef struct {
    char *name;
    int month;
    int year;
    int day;
} persons_t;

persons_t *get_persons(char *file_name, int *number)
{
    char buffer[100];
    int counter = 0;
    FILE *input_file = fopen(file_name, "r");
    if (input_file == NULL){
        printf("Error occured!");
        return -1;
    }

    while(!feof(input_file)){
        fgets(buffer,100,input_file);
        counter++;
    }

    *number = counter;
    fclose(input_file);

    persons_t *persons = (persons_t*)malloc(sizeof(persons_t) * counter);

    input_file = fopen(file_name, "r");

    for (int i = 0; i < counter; ++i) {
        fgets(buffer,100,input_file);
        char* name;
        char* year;
        char* month;
        char* day;

        name = strtok(buffer,",");
        year = strtok(NULL, "-");
        month = strtok(NULL, "-");
        day = strtok(NULL, "-");

        persons[i].name = name;
        persons[i].year = atoi(year);
        persons[i].day = atoi(day);
        persons[i].month = atoi(month);

        printf("name: %s, birthday: %d-%d-%d\n", persons[i].name, persons[i].year, persons[i].month, persons[i].day);
    }
}

char list_persons_in_age_group(persons, nmbr_of_persons, BETWEEN_30_AND_35)
{

}

/*
Implement the functions used below, and make the program work.
*/


int main()
{
    int nmbr_of_persons;

    persons_t* persons = get_persons("../../../persons.txt", &nmbr_of_persons);
    /*
    This function should read persons data from a text file
    and return the datas into a structure-array.
    As you can see, you have to use dynamic memory allocation.
    */


    list_persons_in_age_group(persons, nmbr_of_persons, BETWEEN_30_AND_35);
    /*
    This function should print out the filtered informations based on the given age group
    to the console in the following way:
    Persons in the given age group:
    Pop Simon, aged 28
    Major Anna, aged 26
    */

    return 0;
}

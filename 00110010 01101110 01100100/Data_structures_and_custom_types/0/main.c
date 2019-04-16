#include <stdio.h>
#include <string.h>

//STRUCT

typedef struct team {
    char name[50];
    char main_tecnology[50];
    char number_of_members;
} team_t;

//ENUM

typedef enum {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
} Days;

const char* get_day_name(Days day)
{
    switch (day)
    {
        case MONDAY: return "Monday";
        case TUESDAY: return "Tuesday";
        case WEDNESDAY: return "Wednesday";
        case THURSDAY: return "Thursday";
        case FRIDAY: return "Friday";
        case SATURDAY: return "Saturday";
        case SUNDAY: return "Sunday";
    }
}

//BIT FIELD

typedef struct {
    int age;
    int weight;
    int height;
} person_t;

typedef struct{
    int age : 2;
    int height : 2;
    int weight : 2;
} person_bitfield_t;

int main() {
    /* --------STRUCT------------
    team_t team;
    strcpy(team.name, "Jade-Selection");
    strcpy(team.main_tecnology, "Ruby-On-Rails");
    team.number_of_members = 5;

    printf("The team is: %s , there are %d people working with %s.\n", team.name, team.number_of_members, team.main_tecnology);
    -----------STRUCT-----------*/

    /* --------ENUM--------------
    printf("%s\n",get_day_name(TUESDAY));
    -----------ENUM-------------*/

    /* -------BIT FIELD----------
    printf("%d\n", sizeof(person_t));
    printf("%d\n", sizeof(person_bitfield_t));
    ----------BIT FIELD----------*/

    int num;
    FILE *fptr;
    fptr = fopen("program.txt", "w");

    printf("Enter num: ");
    scanf("%d",&num);

    for (int i = 0; i < num; ++i) {
        fprintf(fptr, "%d\n", num);
    }

    fclose(fptr);

    return 0;
}
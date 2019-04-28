#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Digimon database!
 * You should store the following data in a structure
 *  - the name of the digimon (which is shorter than 128 characters)
 *  - the age of the digimon (in years)
 *  - the health of the digimon (between 0-100)
 *  - the name of the tamer (which is shorter than 256 characters)
 *  - the digivolution level of the digimon (as a custom type, see below)
 *
 * You should store the digivolution level in an enumeration
 * the valid digivolution levels are:
 *  - baby
 *  - in-training
 *  - rookie
 *  - champion
 *  - ultimate
 *  - mega
 *
 * The digimons are stored in an array.
 *
 * Write the following functions:
 * 1) Get minimum health index
 *      - parameters:
 *          - array
 *          - array length
 *      - it returns the index of the minimal health digimon in the "array"
 * 2) Get same digivolution level count
 *      - parameters:
 *          - array
 *          - array length
 *          - digivolution level
 *      - it returns the count of digimons which are at "digivolution level"
 * 3) Get same tamer count
 *      - parameters:
 *          - array
 *          - array length
 *          - tamer name
 *      - it returns the count of the digimons which have the same tamer as "tamer name"
 * 4) Get average health of the same tamer
 *      - parameters:
 *          - array
 *          - array length
 *          - tamer name
 *      - it returns the average health of the digimons which have the same tamer as "tamer name"
 *
 * Don't forget to handle invalid inputs (NULL pointers, invalid values etc.)
 */
typedef enum{
    BABY,
    IN_TRAINING,
    ROOKIE,
    CHAMPION,
    ULTIMATE,
    MEGA
}digivolution_t;

typedef struct digimon{
    char digimon_name[127];
    int digimon_age;
    int digimon_health;
    char digimon_tamer[255];
    digivolution_t digivolution;
} digimon_t;

int min_health_index(digimon_t* digimon, int num_digimons)
{
    //n = sizeof(digimon);
    int index_of_min_hp = 0;
    int min_hp = digimon[0].digimon_health;
    for (int i = 0; i < num_digimons; ++i) {
        if(min_hp > digimon[i].digimon_health) {
            min_hp = digimon[i].digimon_health;
            index_of_min_hp = i;
        }
    }
    return index_of_min_hp;
}

int same_digivolution_count(digimon_t* digimon, int num_digimons, digivolution_t digivolution)
{
    int same_digivolution = 0;
    for (int i = 0; i < num_digimons; ++i) {
        if(digimon[i].digivolution == digivolution){
            same_digivolution++;
        }
    }
    return same_digivolution;
}

int same_tamer_count(digimon_t* digimon, int num_digimons, char* tamer_name)
{
    int same_tamer = 0;
    for (int i = 0; i < num_digimons; ++i) {
        if (!strcmp(digimon[i].digimon_tamer, tamer_name)){
            same_tamer++;
        }
    }
    return same_tamer;
}

int average_health_of_same_tamer(digimon_t* digimon, int num_digimons, char* tamer_name)
{
    int same_tamer = 0;
    int sum_of_health = 0;
    for (int i = 0; i < num_digimons; ++i) {
        if (!strcmp(digimon[i].digimon_tamer,tamer_name)) {
            same_tamer++;
            sum_of_health += digimon[i].digimon_health;
        }
    }
    return sum_of_health / same_tamer;
}

int main()
{
    digimon_t digimon1;
    digimon1.digimon_age = 5;
    digimon1.digimon_health = 50;
    digimon1.digivolution = ROOKIE;
    strcpy(digimon1.digimon_name, "Kék");
    strcpy(digimon1.digimon_tamer, "Trainer 1");

    digimon_t digimon2;
    digimon2.digimon_age = 15;
    digimon2.digimon_health = 200;
    digimon2.digivolution = ULTIMATE;
    strcpy(digimon2.digimon_name, "Piros");
    strcpy(digimon2.digimon_tamer, "Trainer 2");

    digimon_t digimon3;
    digimon3.digimon_age = 20;
    digimon3.digimon_health = 500;
    digimon3.digivolution = MEGA;
    strcpy(digimon3.digimon_name, "Rózsaszín");
    strcpy(digimon3.digimon_tamer, "Trainer 1");

    digimon_t digimon4;
    digimon4.digimon_age = 2;
    digimon4.digimon_health = 10;
    digimon4.digivolution = IN_TRAINING;
    strcpy(digimon4.digimon_name, "Lila");
    strcpy(digimon4.digimon_tamer, "Trainer 1");

    digimon_t digimons[] = {digimon1, digimon2, digimon3, digimon4};


    printf("%d\n", min_health_index(digimons,4));

    printf("%d\n", same_digivolution_count(digimons, 4, ROOKIE));

    printf("%d\n", same_tamer_count(digimons,4,"Trainer 1"));

    printf("%d\n", average_health_of_same_tamer(digimons,4, "Trainer 1"));

    return 0;
}
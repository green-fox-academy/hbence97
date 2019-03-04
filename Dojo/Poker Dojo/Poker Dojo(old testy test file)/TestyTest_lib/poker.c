//
// Created by hegye on 2019. 03. 04..
//
#include "poker.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void poker_testing(char* first_player, char *card_set1, char* second_player, char* card_set2) {

/*int str_to_card (const char* test_string)
{

}*/
    char* set1[5];
    int counter1 = 0;
    for (char *p = strtok(card_set1, " "); p != NULL; p = strtok(NULL, " ")){
        set1[counter1] = p;
        counter1 ++;
    }

    char* set2[5];
    int counter2 = 0;
    for (char *p = strtok(card_set2, " "); p != NULL; p = strtok(NULL, " ")){
        set2[counter2] = p;
        counter2 ++;
    }

    char set1_card1[2];
}
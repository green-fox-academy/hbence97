#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The rich uncle has just died and you need to distribute his heritage among the relatives. The money you have to distribute is $1024
// Generate a random number between 20 and 50. This number will be the amount of relatives that showed up at the inheritance party.
// Allocate an array for them. Each element of the array will represent a relative.
// You need to generate a random number between 0 and the number of relatives to decide which one is the winner.
// The winner always gets the half of the remaining money. You need to generate random numbers until all the money is gone.
// Print the amount of money each relative got on the party. Print 0 for the unlucky ones.

//For example: 0,0,0,0,128,4,0,0,2,0,512,0,0,0,0,0,0,32,0,64,0,0,1,8,0,0,16,256

int main()
{
    int heritage = 1024;
    srand(time(NULL));
    int relatives = rand()% 15 + 8;
    int *pointer;
    pointer = (int*) malloc(relatives * (sizeof(int)));
    int winner = rand() % relatives + 0;
    for (int i = 0; i < relatives; ++i) {
        pointer[i] = heritage;
        if (heritage == 0){
            printf("Well you didnt get any money from your uncle.\n");
        } else {
            pointer[i] = winner;
                pointer[winner] += heritage;
                printf("You got %d money.\n", heritage);
                heritage /= 2;
            }
        }
    free(pointer);
    return 0;
}
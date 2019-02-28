#include <stdio.h>
// Write a program that stores a number, and the user has to figure it out.
// The user can input guesses, after each guess the program would tell one
// of the following:
//
// The stored number is higher
// The tried number is lower
// You found the number: 8

int main() {
    int myNumber = 5;
    int yourNumber;


    while(myNumber != yourNumber){
        printf("Guess the number I thought about between 1 - 10\n");
        scanf("%d", &yourNumber);

        if(yourNumber < myNumber){
            printf("The stored number is higher\n");
        } else if (yourNumber > myNumber){
            printf("The stored number is smaller\n");
        } else {
            printf("You found the number: %d\n",myNumber);
        }
    }
    return 0;
}
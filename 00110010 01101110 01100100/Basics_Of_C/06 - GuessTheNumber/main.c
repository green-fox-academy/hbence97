#include <stdio.h>
// Write a program that stores a number, and the user has to figure it out.
// The user can input guesses, after each guess the program would tell one
// of the following:
//
// The stored number is higher
// The stried number is lower
// You found the number: 8
int main()
{
    int number = 28;
    int guess;

    printf("Try to guess the number I was thinking of!\n");
    while (guess != number) {
        scanf("%d", &guess);
        if (guess < number) {
            printf("The stored number is bigger\n");
        }
        if (guess > number) {
            printf("The stored number is smaller!\n");
        }
    }
    if (guess == number){
        printf("You found the the number: %d", number);
    }
    return 0;
}
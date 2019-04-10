#include <stdio.h>
#include <stdlib.h>

int old_enough(int age)
{
    if (age < 18) {
        printf("You are not able to buy alcohol in Hungary.\n");
    } else {
        printf("You can buy alcohol in Hungary.\n");
    }
    return 0;
}

int main()
{
    // Create a program which asks for the age of the user and stores it
    // Create a function which takes that age as a parameter and returns if the user is
    // old enough to buy himself alcohol in Hungary
    printf("Tell me your age.\n");
    int your_age;
    scanf("%d", &your_age);
    printf(old_enough(your_age));

    return 0;
}
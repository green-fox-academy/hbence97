#include <stdio.h>
#include <stdlib.h>

int yourAge(int testAge);

int main()
{
    // Create a program which asks for the age of the user and stores it
    // Create a function which takes that age as a parameter and returns if the user is
    // old enough to buy himself alcohol in Hungary
    printf("How old are you?\n");
    int age;
    scanf("%d", &age);
    printf(yourAge(age));



    return 0;
}

int yourAge(int testAge)
{
    if (testAge < 18) {
        return "You are too young to buy alcohol.";
    } else if (testAge >= 18) {
        return "You can buy alcohol dude, but be careful with it.";
    }
}
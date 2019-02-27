#include<stdio.h>

int main()
{
    // Write a program that prints a few details to the terminal window about you
    // It should print each detail to a new line.
    //  - Your name
    //  - Your age
    //  - Your height in meters (as a decimal fraction)
    //
    //  Use variables to store the informations!
    //
    //  Example output:
    //  John Doe
    //  31
    //  1.87
    char myName [] = "Bence";
    int age = 21;
    float height = 1.71;

    printf("My name is %s\n", myName );
    printf("My age is %d", age);
    printf("My height is %.2f", height);


    return 0;
}
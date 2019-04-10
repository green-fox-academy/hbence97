#include <stdio.h>
#include <stdlib.h>
#include "pi.h"
//#define PI 3.14 U CAN DO IT LIKE THIS AS WELL.

// define a variable called PI with the value of 3.14
// create a function which takes the radius of a circle as a parameter
// and return the area of that circle
// area = radius * radius * PI

int main()
{
    float r = 5.5;
    printf("Your circle's area is: %.2f\n",area(r));
    printf("Your circle's circumference is: %.2f\n", circumference(r));
    return 0;
}
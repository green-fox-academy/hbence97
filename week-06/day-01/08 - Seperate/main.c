#include <stdio.h>
#include <stdlib.h>
#include "calculate_area.h"
//#define PI 3.14
//#define AREA radius * radius * PI
// define a variable called PI with the value of 3.14
// create a function which takes the radius of a circle as a parameter
// and return the area of that cirle
// area = radius * radius * PI
/*
double circle(double radius)
{
    return (radius * radius * PI);
}
*/
double circumference(double radius)
{
    return (2 * (PI * radius) );
}

int main()
{
    //double radius = 5;
    //printf("%.0f", circle(20));
    //printf("%f", AREA);
    printf("%.1f", circumference(10));
    return 0;
}
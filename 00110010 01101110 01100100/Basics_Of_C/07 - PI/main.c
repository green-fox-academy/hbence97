#include <stdio.h>
#include <stdlib.h>
//#define PI 3.14 U CAN DO IT LIKE THIS AS WELL.

// define a variable called PI with the value of 3.14
// create a function which takes the radius of a circle as a parameter
// and return the area of that circle
// area = radius * radius * PI

float area(float radius)
{
    float PI = 3.14;
    float area_of_circle = (radius * radius * PI);
    return area_of_circle;
}

int main()
{
    float r = 5.5;
    printf("Your circle's area is: %.2f\n", area(r));
	return 0;
}
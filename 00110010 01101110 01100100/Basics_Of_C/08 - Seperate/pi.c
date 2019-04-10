//
// Created by hegye on 2019. 04. 10..
//

#include "pi.h"

float area(float radius)
{
    float PI = 3.14;
    float area_of_circle = (radius * radius * PI);
    return area_of_circle;
}

float circumference(float radius)
{
    float PI = 3.14;
    float circumference_of_circle = 2 * radius * PI;
    return circumference_of_circle;
}

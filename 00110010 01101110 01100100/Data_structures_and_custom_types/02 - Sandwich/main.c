#include <stdio.h>
#include <string.h>
/*
Create a sandwich struct
It should store:
 - name
 - price (float)
 - weight (float)
Create a function which takes two parameters and returns the price of your order.
The parameters should be:
 - a sandwich struct
 - and an integer that represents how many sandwiches you want to order
*/

typedef struct Sandwich {
    char name[25];
    float price;
    float weight;
} sandwich_t;

float price_of_your_order(sandwich_t sandwich,int number_of_order)
{
    return sandwich.price * number_of_order;
}

int main() {

    sandwich_t sandwich1;
    sandwich1.price = 3.5;

    printf("The price of your order is %.2f", price_of_your_order(sandwich1,3));
    return 0;
}
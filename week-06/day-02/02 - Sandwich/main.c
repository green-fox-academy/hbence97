#include <stdio.h>

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

typedef struct
{
    char* _name;
    float _price;
    float _weight;
    int _order;
} Sandwich_t;

float Price(Sandwich_t sandwich, int _order);

int main()
{
    Sandwich_t sandwich1;
    sandwich1._name = "Cheeseburger";
    sandwich1._price = 3;
    sandwich1._weight = 1;
    sandwich1._order = 12;

    Sandwich_t sandwich2;
    sandwich2._name = "Hamburger";
    sandwich2._price = 2.5;
    sandwich2._weight = 0.9;
    sandwich2._order = 5;

    printf("The price of your sandwiches will be %.1f dollars\n", Price(sandwich1, sandwich1._order));
    printf("The price of your sandwiches will be %.1f dollars\n", Price(sandwich2, sandwich2._order));

    return 0;
}

float Price(Sandwich_t sandwich, int _order)
{
    return (sandwich._price * _order);
}

#include <stdio.h>
/*
Create a struct that represents a House
It should store:
 - The address of the house
 - The price in EUR
 - The number of rooms
 - The area of the house in square meters
The market price of the houses is 400 EUR / square meters
Create a function that takes a pointer to a house and decides if it's worth to buy
(if the price is lower than the calculated price from it's area)
Create a function that takes an array of houses (and it's length), and counts the
houses that are worth to buy.
*/

typedef struct House{
    char* adress;
    float price;
    int rooms;
    float area;
} house_t;

int worth_to_buy(house_t *house)
{
    int result = 0;
    if((house->price / house->area) < 400){
        result = 1; //This means the house is worth to buy,0 if not.
    }
    return result;
}

int list(house_t house[], int length) //Honnan tudja, hogy a length mekkora.
{
    int count = 0;
    for (int i = 0; i < length; ++i) {
        if(worth_to_buy(&house[i]))
            count++;
    }
    return count;
}

int main()
{
    house_t house[3];

    house[0].area = 40;
    house[0].price = 500;

    house[1].area = 30;
    house[1].price = 40000;

    house[2].area = 400;
    house[2].price = 20000;

    printf("%d\n",worth_to_buy(&house[2])); // 1 Means worth buying, 0 Not worth.

    printf("There are %d house(s) that are worth to buy.\n",list(house,3));

    return 0;
}
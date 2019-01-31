#include <iostream>
#include <string>
int sum(int num[], int size);

int main(int argc, char* args[]) {

    // Write a function called `sum` that returns the sum of numbers from zero to the given parameter

    int num [7] = {5,8,12,14,16,20,24};
    std::cout << sum(num, 7) << std::endl;

    return 0;
}

int sum(int num[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += num[i];
    }
    return sum;
}
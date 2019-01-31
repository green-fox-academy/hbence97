#include <iostream>

// Write a recursive function that takes one parameter: n and adds numbers from 1 to n.

int add (int);

int main()
{
    int n = 5;
    //std::cout << "Give me a number! " << std::endl;
    //std::cin >> n;

    int s = add(n);

    std::cout << s << std::endl;
    return 0;
}

int add (int adder) {

        int sum;
        if (adder >= 1) {

            sum = adder + add(adder - 1);
            return sum;

        }

return 0;

}
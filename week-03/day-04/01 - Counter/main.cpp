#include <iostream>

// Write a recursive function that takes one parameter: n and counts down from n.

void counter(int);

int main() {
    int num;
    std::cout << "Give me a number" << std::endl;
    std::cin >> num;

    counter(num);

    return 0;
}

void counter(int count) {

    if (count >= 1) {
        std::cout << "Number: " << count << std::endl;
        counter(count - 1);
    }
}


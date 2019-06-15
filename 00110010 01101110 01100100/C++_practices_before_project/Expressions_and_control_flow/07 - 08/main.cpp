#include <iostream>

int main() {

    /* 07 */
    // Store your favorite number in a variable (as an integer)
    // And print it like this: "My favorite number is: 8"
    int favorite_number = 12;
    std::cout << "My favorite number is: " << favorite_number << std::endl;

    /* 08 */
    // Swap the values of the variables
    int a = 123;
    int b = 526;
    int c = a;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << "Now after the swap its" << std::endl;
    a = b;
    std::cout << a << std::endl;
    std::cout << c << std::endl;

    return 0;
}
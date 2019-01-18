#include <iostream>
// Swap the values of the variables

int main(int argc, char* args[]) {

    int a = 123;
    int b = 526;

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    std::swap(a , b);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    return 0;
}
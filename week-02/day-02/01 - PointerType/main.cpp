#include <iostream>
    // Create a pointer for each variable and print out the memory addresses of that variables
    // Print out the values of the pointers
    int main ()
{
    int a = 31;
    double b = 432.2;
    std::string name = "Bob";

    std::cout << &a << std::endl;
    std::cout << a << std::endl;
    std::cout << &b << std::endl;
    std::cout << b << std::endl;
    std::cout << &name << std::endl;
    std::cout << name << std::endl;

    return 0;
}
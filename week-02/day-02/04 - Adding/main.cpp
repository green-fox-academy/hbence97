#include <iostream>
// Add two numbers using pointers
int main()
{
    int a = 20;
    int b = 17;
    int *apointer = &a;
    int *bpointer = &b;
    int sum = *apointer + *bpointer;
    std::cout<< sum << std::endl;

    return 0;
}
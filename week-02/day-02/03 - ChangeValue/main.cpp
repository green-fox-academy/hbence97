#include <iostream>
    // Change the value of the variable called 'temperature' using a pointer
    // (you have to create the pointer first)
    int main ()
{
    float temperature = 21.3;
    float newtemperature = 23.3;
    float *newtemperaturepointer = nullptr;
    newtemperaturepointer = &newtemperature;

    std::cout << "The new value is " << *newtemperaturepointer << std::endl;

    return 0;
}
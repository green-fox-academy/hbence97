#include <iostream>
    // Print out the value of the variable called 'age' using a pointer
    // (you have to create the pointer first)
int main () {
        int age = 31;
        int *agepointer = nullptr ;
        agepointer = &age;

        //*agepointer = 32;

        std::cout << "The value is: " <<  *agepointer << std::endl;

        return 0;
    }
#include <iostream>
    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the values of that array using pointers again
    int main()
    {
    int numbers[5];
    int *numberspointer = nullptr;
    numberspointer = numbers;

    std::cout << "Give me 5 numbers :" << std::endl;


    for (int i = 0 ; i < 5 ; i++){
        std::cin >> numbers[i];

    }
    for (int i = 0 ; i < 5 ; i++) {
        std::cout << " " << numbers[i];

    }
    return 0;
}
#include <iostream>

    // Modify this program to greet user instead of the World!
    // The program should ask for the name of the user

int main(int argc, char* args[]) {

    std::string a;

    std::cout << "What's your name? " << std::endl;

    std::cin >> a;

    std::cout << "Hello " << a << std::endl;

    return 0;
}
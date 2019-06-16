#include <iostream>

int main(int argc, char* args[]) {

    // Modify this program to greet user instead of the World!
    // The program should ask for the name of the user

    std::string your_name;

    std::cout << "Hello, please tell me your name." << std::endl;
    std::cin >> your_name;

    std::cout << "Hi " << your_name << std::endl;

    return 0;
}
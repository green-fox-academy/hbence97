#include <iostream>
    // Write a program that asks for two numbers
    // The first number represents the number of girls that comes to a party, the
    // second the boys
    // It should print: The party is excellent!
    // If the the number of girls and boys are equal and 20 or more people are coming to the party
    //
    // It should print: Quite cool party!
    // If there are 20 or more people coming to the party but the girl - boy ratio is not 1-1
    //
    // It should print: Average party...
    // If there are less people coming than 20
    //
    // It should print: Sausage party
    // If no girls are coming, regardless the count of the people
int main(int argc, char* args[]) {

    int num1;
    int num2;
    std::cout << "How many girls are in the party" << std::endl;
    std::cin >> num1;
    std::cout << "How many boys are in the party" << std::endl;
    std::cin >> num2;

    if (num1 + num2 >= 20 & num1 == num2) {
        std::cout << "The party is excellent" << std::endl;
    }
    if (num1 + num2 >= 20 & num1 != num2 & num1 != 0) {
        std::cout << "Quite cool party" << std::endl;
    }
    if (num1 + num2 < 20 & num1 >= 1 & num2 >= 1 ) {
        std::cout << "Average party" << std::endl;
    }
    if (num1 < 1 ) {
        std::cout << "Sausage party" << std::endl;
    }


    return 0;
}
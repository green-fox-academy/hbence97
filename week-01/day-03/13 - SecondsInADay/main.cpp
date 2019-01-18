#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that prints the remaining seconds (as an integer) from a
    // day if the current time is represented by the variables

    int currentHours = 14;
    int currentMinutes = 34;
    int currentSeconds = 42;
    int a = 24 - currentHours;
    int b = 60 - currentMinutes;
    int c = 60 - currentSeconds;
    int anHourInSeconds = 60 * 60;
    int aMinuteInSeconds = 60;
    std::cout << a << "hours left" << std::endl;
    std::cout << b << "minutes left" << std::endl;
    std::cout << c << "seconds left" << std::endl;

    std::cout << anHourInSeconds << " is 1 hour in seconds " << std::endl;
    std::cout << anHourInSeconds * 10 << " is 10 hours in seconds" << std::endl;

    std::cout << (anHourInSeconds * 10) + 60*(60 - 34) + (c) << " seconds left in a day!" << std::endl;



    return 0;
}
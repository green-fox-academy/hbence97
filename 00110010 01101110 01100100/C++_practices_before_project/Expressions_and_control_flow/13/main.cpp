#include <iostream>

int main(int argc, char* args[]) {

    int currentHours = 14;
    int currentMinutes = 34;
    int currentSeconds = 42;

    int remaining_hours = 24 - currentHours;
    int remaining_minutes = 60- currentMinutes;
    int remaining_seconds = 60 - currentSeconds;

    // Write a program that prints the remaining seconds (as an integer) from a
    // day if the current time is represented by the variables

    std::cout << "There are " << remaining_hours << " hours " << remaining_minutes << " minutes and " << remaining_seconds << " seconds left from the day" << std::endl;

    return 0;
}
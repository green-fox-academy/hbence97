#include <iostream>

int main(int argc, char* args[]) {

    // An average Green Fox attendee codes 6 hours daily
    // The semester is 17 weeks long
    //
    // Print how many hours is spent with coding in a semester by an attendee,
    // if the attendee only codes on workdays.
    //
    // Print the percentage of the coding hours in the semester if the average
    // working hours weekly is 52

    int daily = 6;
    int week = 5;
    int semester = 17;
    int a = daily * week * semester;

    std::cout << a << " hours is spent coding." << std::endl;

    int b = 5*6;
    int c = 52;

    std::cout << b % c << std::endl;

    return 0;
}
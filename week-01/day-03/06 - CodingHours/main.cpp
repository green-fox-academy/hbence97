#include <iostream>

    // An average Green Fox attendee codes 6 hours daily
    // The semester is 17 weeks long
    //
    // Print how many hours is spent with coding in a semester by an attendee,
    // if the attendee only codes on workdays.
    //
    // Print the percentage of the coding hours in the semester if the average
    // working hours weekly is 52

    int main(int argc, char* args[]) {

    int a;
    int b;
    int c;

    a = 6;
    b = 17;
    c = 52;

    std::cout << b * c  << " hours is spent coding in a semester" << std::endl;

        std::cout << ( a * b * c) / ( b * c) * 100 << "&" << " is the percent of the average coding hours" << std::endl;


    return 0;
}
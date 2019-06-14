#include <iostream>
#include <string>

int main() {

    /* 04 */
    std::string my_name = "Hegyes Bence";
    int age = 21;
    float height = 1.72;

    std::cout << my_name << std::endl;
    std::cout << age << std::endl;
    std::cout << height << std::endl;

    /* 05 */
    int a = 13;
    int b = 22;
    // Print the result of 13 added to 22
    std::cout << a + b << std::endl;
    // Print the result of 13 substracted from 22
    std::cout << b - a << std::endl;
    // Print the result of 22 multiplied by 13
    std::cout << b * a << std::endl;
    // Print the result of 22 divided by 13 (as a decimal fraction)
    std::cout << (float) b / (float) a << std::endl;
    // Print the integer part of 22 divided by 13
    std::cout << b / a << std::endl;
    // Print the remainder of 22 divided by 13
    std::cout << b % a << std::endl;

    /* 06 */
    // An average Green Fox attendee codes 6 hours daily
    // The semester is 17 weeks long
    //
    // Print how many hours is spent with coding in a semester by an attendee,
    // if the attendee only codes on workdays.
    //
    // Print the percentage of the coding hours in the semester if the average
    // working hours weekly is 52
    int daily = 6;
    int semester = 17;

    std::cout << "Hours spent coding in a semester: " << (5 * daily) * semester << std::endl;

    std::cout << "The average of the semester is " << ((5 * daily * semester) / (double (17 * 52))) * 100 << "%" << std::endl;

    return 0;
}
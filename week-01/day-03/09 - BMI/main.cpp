#include <iostream>
// Print the Body mass index (BMI) based on these values

int main(int argc, char* args[]) {

    double massInKg = 81.2;
    double heightInM = 1.78;

    std::cout << massInKg / 1.78 * 1.78 << " is the BMI " << std::endl;
    return 0;
}
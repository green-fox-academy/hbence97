#include <iostream>

int main(int argc, char* args[]) {

    double massInKg = 81.2;
    double heightInM = 1.78;
    double bmi = massInKg / (heightInM * heightInM);

    // Print the Body mass index (BMI) based on these values

    std::cout << bmi << std::endl;

    return 0;
}
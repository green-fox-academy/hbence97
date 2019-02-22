#include <iostream>
#include <vector>

void digits(int num);

int main() {
    int num;
    std::cout << "Give me a number, and I'll tell you if it's an Armstrong number!" << std::endl;
    std::cin >> num;
    digits(num);
    return 0;
}

void digits(int num) {
    std::vector<int> digitCollector;
    int copy = num;

    while(copy != 0) {
        digitCollector.push_back(copy % 10);
        copy = copy / 10;
    }

    int result = 0;

    for (int i = 0; i < digitCollector.size(); ++i) {
        int numberMultiplier = 1;
        for (int j = 0; j < digitCollector.size(); ++j) {
            numberMultiplier = numberMultiplier * digitCollector[i];
        }
        result = result + numberMultiplier;
    }
    if (result == num){
        std::cout << "Your number is an Armstrong number" << std::endl;
    } else {
        std::cout << "Your number is not an Armstrong number" << std::endl;
    }
}
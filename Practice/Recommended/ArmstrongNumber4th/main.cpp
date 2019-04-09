#include <iostream>
#include <vector>

void digits(int num);

int main() {
    int num;
    std::cout << "Tell me a number, and I'll tell you if it's an Armstrong number!" << std::endl;
    std::cin >> num;
    digits(num);
    return 0;
}

void digits(int num){
    std::vector<int> digitCollector;
    int copy = num;
    int result = 0;
    while (copy != 0){
        digitCollector.push_back(copy % 10);
        copy = copy / 10;
    }
    for (int i = 0; i < digitCollector.size(); ++i) {
        int vectorElementMultiplier = 1;

        for (int j = 0; j < digitCollector.size(); ++j) {
            vectorElementMultiplier = vectorElementMultiplier * digitCollector[i];
        }
        result = result + vectorElementMultiplier;
    }
    if (result == num) {
        std::cout << "Your number is an Armstrong number" << std::endl;
    } else {
        std::cout << "Your number is not an Armstrong number" << std::endl;
    }
}

#include <iostream>
#include <vector>

void armstrong(int num);

int main() {
    int num;
    std::cout << "Tell me a number and I will tell your if it's an Armstrong number or not!" << std::endl;
    std::cin >> num;
    armstrong(num);
    return 0;
}

void armstrong(int num){
    std::vector <int> digitCollector;
    int result = 0;
    int copy = num;
    while(copy != 0){
        digitCollector.push_back(copy % 10);
        copy = copy / 10;
    }

    for (int i = 0; i <digitCollector.size(); ++i) {
        int counter = 1;
        for (int j = 0; j < digitCollector.size(); ++j) {
            counter = counter * digitCollector[i];
        }
    result = result + counter;
    }
    if (result == num){
        std::cout << "Your number is an Armstrong number!" << std::endl;
    } else {
        std::cout << "Your number is not an Armstrong number!" << std::endl;
    }
}
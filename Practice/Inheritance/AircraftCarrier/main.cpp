#include <iostream>
#include "F16.h"
int main() {
    F16 aircraft1;
    std::cout << aircraft1.refill(300) << std::endl;
    std::cout << aircraft1.getType() << std::endl;
    std::cout << aircraft1.getStatus() << std::endl;
    std::cout << aircraft1.fight() << std::endl;
    std::cout << aircraft1.refill(10) << std::endl;

    return 0;
}
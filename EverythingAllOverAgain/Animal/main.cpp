#include <iostream>
#include "animal.h"

int main() {
    Animal an("cat", 50, 50);
    std::cout << an.toString() << std::endl;
    an.play();
    an.drink();
    std::cout << an.toString();
    return 0;
}
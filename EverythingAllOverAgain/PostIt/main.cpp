#include <iostream>
#include "postIt.h"
int main() {
    PostIt pi1("blue ", "Idea 1", "orange ");
    PostIt pi2("black ", "Awesome", "pink ");
    PostIt pi3("green ", "Superb!", "yellow ");

    std::cout << pi1.toString() << std::endl;
    std::cout << pi2.toString() << std::endl;
    std::cout << pi3.toString() << std::endl;
    return 0;
}
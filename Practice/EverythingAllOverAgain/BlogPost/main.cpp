#include <iostream>
#include "blogPost.h"

int main() {
    BlogPost bp("John Doe", "Lorem Ipsum", "Lorem ipsum dolor sit amet.", "2000.05.04");

    std::cout << bp.toString() << std::endl;
    return 0;
}
#include <iostream>
#include "Sharpie.h"

int main() {
    Sharpie sh(" blue",2.2);
    sh.use();
    sh.use();
    std::cout << sh.inkAmount << std::endl;



    return 0;
}
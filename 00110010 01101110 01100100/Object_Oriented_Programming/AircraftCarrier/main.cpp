#include <iostream>
#include "f16.h"
#include "f35.h"

int main() {

    F16 f16;
    f16.getType();
    f16.fight();
    std::cout <<f16.getStatus("F16", 8, 30, 210);

    return 0;
}
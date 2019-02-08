#include <iostream>
#include "F16.h"

int main() {

    F16 fa;
    fa.getStatus();
    fa.fight();
    fa.refill(200);
    fa.getStatus();
    return 0;
}
#include <iostream>
#include <string>

void factorio(int x, int& y);

int main() {

    // - Create a function called `factorio`
    //   it should calculate its input's factorial.
    //   it should not return it, but take an additional integer parameter and overwrite its value.

    int num1 = 6 ;
    int y = 0;
    factorio(num1, y);
    std::cout << y << std::endl;

    return 0;
}
void factorio(int x, int& y){
    y = x;
    for(int i = x-1; i > 0 ; i--)
        y *= i;

}
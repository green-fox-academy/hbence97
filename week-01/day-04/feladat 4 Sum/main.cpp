#include <iostream>
#include <string>

int sum(int num [], int size);


int main(int argc, char* args[]) {

    // - Write a function called `sum` that sum all the numbers
    //   until the given parameter and returns with an integer


    int numbers[] = {2,4,6,8,10};

    std::cout << sum(numbers, 5) << std::endl;
    return 0;
}
int sum(int num [], int size){

    int sum = 0;
    for (int i = 0; i < size; i++) {
    sum+= num[i];
}
return sum;
}
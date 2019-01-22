#include <iostream>
// Create a function which takes an array (and it's lenght) and a number as a parameter
// the function should return index where it found the given value
// if it can't find the number return 0
int lookForValue (int array[], int size, int num) {
    for (int i = 0 ; i < size ; i ++) {
        if (array[i] == num) {
            return i+1;
      } else{
            return 0;
        }
  } //return 0;

}

int main()
{

    int num;
    std::cout << "Give me a number!" << std::endl;
    std::cin >> num;

    int array[] = {2, 4, 6, 8, 10};
    int size = (sizeof(array)/sizeof(array[0]));
    lookForValue(array, size, num);

    std::cout << lookForValue(array, size, num) << std::endl;
    return 0;
}
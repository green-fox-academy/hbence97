#include "pch.h"
#include <iostream>
#include <vector>

void bubbleSort(std::vector<int> &array);
void printArray(std::vector<int> &arr);
void printArrayBackwards(std::vector<int> &arr);

int main(int argc, char ** argv)
{
	std::vector<int> array = {64, 32, 37, 4, 56, 76, 54, 21, 81};
	bubbleSort(array);
	std::cout << "Sorted array: " << std::endl;
	printArray(array);
	printArrayBackwards(array);
	
	return 0;
}

void bubbleSort(std::vector<int> &array) {
	bool swapped;
	int temporary;
	for (int i = 1; i < array.size(); i++) {
		swapped = false;
		for (int j = 0; j < array.size() - i; j++) {
			if (array[j] > array[j + 1]) {
				temporary = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temporary;
				swapped = true;
			}
		}
		if (swapped == false) {
			break;
		}
	}
}
 
void printArray(std::vector<int> &arr) {
	for (int i =  0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

void printArrayBackwards(std::vector<int> &arr) {
	std::reverse(arr.begin(), arr.end());
	for (std::vector<int>::iterator i = arr.begin(); i != arr.end(); ++i) {
		std::cout << *i << " ";
	}
	std::cout << "\n";
}
#include "pch.h"
#include <iostream>
#include <vector>

std::vector<int> bubbleSort(std::vector<int> &array);

// WHEN THE bubbleSort FUNCTION WAS VOID, WE NEEDED EVERYTHING WHAT IS COMMENTED OUT

//void printArray(std::vector<int> &arr);
//void printArrayBackwards(std::vector<int> &arr);

int main(int argc, char ** argv)
{
	std::vector<int> vector = {64, 32, 37, 4, 56, 76, 54, 21, 81};
	bubbleSort(vector);
	std::cout << "Sorted array: " << std::endl;
    for (int i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << " ";
    }
	//printArray(array);
	//printArrayBackwards(array);
	
	return 0;
}

std::vector<int> bubbleSort(std::vector<int> &originalVector) {
	bool swapped;
	int temporary;
    std::vector<int> resultVector;
	for (int i = 1; i < originalVector.size(); i++) {
		swapped = false;
		for (int j = 0; j < originalVector.size() - i; j++) {
			if (originalVector[j] > originalVector[j + 1]) {
				temporary = originalVector[j];
				originalVector[j] = originalVector[j + 1];
				originalVector[j + 1] = temporary;
				swapped = true;
			}
		}
        resultVector = originalVector;
		if (swapped == false) {
			break;
		}
	}
    return resultVector;
}
/*
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
}*/
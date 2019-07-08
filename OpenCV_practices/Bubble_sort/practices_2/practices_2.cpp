#include "pch.h"
#include <iostream>

void swap(int *elementOne, int *elementTwo);
void bubbleSort(int arr[], int n);
void printArray(int arr[], int sizeOfArray);


int main(int argc, char ** argv)
{
	int array[] = {64, 32, 37, 4, 56, 76, 54, 21, 81};
	int n = sizeof(array) / sizeof(array[0]);
	bubbleSort(array, n);
	std::cout << "Sorted array: " << std::endl;
	printArray(array, n);
	
	return 0;
}

void swap(int *firstElement, int *secondElement) {
	int temporary = *firstElement;
	*firstElement = *secondElement;
	*secondElement = temporary;
}

void bubbleSort(int array[], int n) {
	bool swapped;
	for (int i = 0; i < n-1; i++) {
		swapped = false;
		for (int j = 0; j < n-i-1; j++) {
			if (array[j] > array[j + 1]) {
				swap(&array[j], &array[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false) {
			break;
		}
	}
}

void printArray(int arr[], int sizeOfArray) {
	for (int i = 0; i < sizeOfArray; i++) {
		std::cout << arr[i] << " ";
	}
}
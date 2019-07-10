#include "pch.h"
#include <iostream>
#include <vector>

int partition(int *array, int start, int end);
void quicksort(int *array, int start, int end);

int main(int argc, char** argv)
{
    int array[10] = { 10, 2, 35 ,4, 21, 56 ,48 ,64 ,90 ,54 };

    quicksort(array, 0, 10 - 1);
    for (int i = 0; i < 10; i++)
    {
        std::cout << array[i] << " ";
    }
	return 0;
}

int partition(int *array, int start, int end) {
    int pivot = array[end];

    // pivotIndex indicates the pivot value index
    int pivotIndex = start;
    int temporary;

    // Here we check if the array's index is less than pivot, then we will place it at the left side of the pivot by swapping
    for (int i = start; i < end; i++) {
        if (array[i] <= pivot) {
            temporary = array[i];
            array[i] = array[pivotIndex];
            array[pivotIndex] = temporary;
            pivotIndex++;
        }
    }

    // Here we exchange the value of the pivot and pivotIndex
    temporary = array[end];
    array[end] = array[pivotIndex];
    array[pivotIndex] = temporary;

    // And lastly we return the value of pivotIndex
    return pivotIndex;
}

void quicksort(int *array, int start, int end) {
    if (start < end) {
        int pivotIndex = partition(array, start, end);
        quicksort(array, start, pivotIndex - 1);
        quicksort(array, pivotIndex + 1, end);
    }
}
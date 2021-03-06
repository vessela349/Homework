#include "pch.h"
#include <iostream>
using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void printArray(int arr[], int size) {
	for (size_t i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}


void heapify(int arr[], int size, int index) {
	int biggest, left, right;
	biggest = index;
	left = 2 * index + 1;
	right = 2 * index + 2;

	if (left < size && arr[left] > arr[biggest]) {
		biggest = left;
	}

	if (right < size && arr[right] > arr[biggest]) {
		biggest = right;
	}

	if (biggest != index) {
		swap(arr[index], arr[biggest]);
		heapify(arr, size, biggest);
	}
}

void heapSort(int arr[], int size) {
	for (int i = size / 2 - 1; i >= 0; i--) {
		heapify(arr, size, i);
	}

	for (int i = size - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

void quickSort(int arr[], int startIndex, int endIndex) {
	int i = startIndex, j = endIndex;
	int temp;
	int pivot = arr[(startIndex + endIndex) / 2];

	while (i <= j) {
		while (arr[i] < pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	};

	if (startIndex < j) {
		quickSort(arr, startIndex, j);
	}

	if (endIndex > i) {
		quickSort(arr, i, endIndex);
	}

}

int main() {
	int arr[10] = { 4, 10, 3, 8, 7, 9, 11, 15, 2, 5 };
	int size = 10;
	cout << "Your current array:\n";
	printArray(arr, size);
	heapSort(arr, size);
	cout << "Array sorted with heap sort:\n";
	printArray(arr, size);

	int arr2[9] = { 4, 10, 3, 8, 7, 9, 11, 15, 2 };
	int size2 = 9;
	cout << "Your current array:\n";
	printArray(arr2, size2);
	cout << "Array sorted with quick sort:\n";
	quickSort(arr2, 0, size2-1);
	printArray(arr2, size2);

	return 0;
}
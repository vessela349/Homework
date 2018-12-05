#include "pch.h"
#include <iostream>
using namespace std;

void swapSwap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

/*void heapify(int arr[], int index, int size) {
	int left, right, largest;
	left = 2 * index;
	right = 2 * index + 1;

	largest = index;

	if (left<=size && arr[left]>arr[index]) {
		largest = left;
	}
	else {
		largest = index;
	}
	if (right <= size && arr[right] > arr[largest]) {
		largest = right;
	}
	if (largest != index) {
		swapSwap(arr[index], arr[largest]);

		heapify(arr, largest, size);
	}
}

void buildMaxHeap(int arr[], int size) {
	for (size_t u = size / 2; u >= 1; u--) {
		heapify(arr, u, size);
	}
}

void heapSort(int arr[], int size) {
	buildMaxHeap(arr, size);
	for (size_t i = size; i >= 2; i--) {
		swapSwap(arr[i], arr[1]);
		heapify(arr, 1, i - 1);
	}
}
*/

// function to heapify the array.

void MaxHeapify(int a[], int i, int n)

{

	int j, temp;

	temp = a[i];

	j = 2 * i;

	while (j <= n)

	{

		if (j < n && a[j + 1] > a[j])

			j = j + 1;

		// Break if parent value is already greater than child value.

		if (temp > a[j])

			break;

		// Switching value with the parent node if temp < a[j].

		else if (temp <= a[j])

		{

			a[j / 2] = a[j];

			j = 2 * j;

		}

	}

	a[j / 2] = temp;

	return;

}
void Build_MaxHeap(int a[], int n)

{

	int i;

	for (i = n / 2; i >= 1; i--)

		MaxHeapify(a, i, n);

}
void HeapSort(int a[], int n)

{
	Build_MaxHeap(a, n - 1);
	int i, temp;

	for (i = n; i >= 2; i--)

	{

		// Storing maximum value at the end.

		temp = a[i];

		a[i] = a[1];

		a[1] = temp;

		// Building max heap of remaining element.

		MaxHeapify(a, 1, i - 1);

	}

}



int main() {

	int arr[10] = { 4, 10, 3, 8, 7, 9, 11, 15, 2, 5 };
	int size = 10;
	HeapSort(arr, size-1);
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	return 0;

}

#include <stdio.h>
#include "sort.h"

/**
 * heapify - Perform heapify operation on array
 * @array: Array to heapify
 * @size: Size of the array
 * @idx: Index of the root element
 * @len: Size of the heap
 */
void heapify(int *array, size_t size, int idx, size_t len)
{
	int largest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;

	if (left < (int)len && array[left] > array[largest])
		largest = left;

	if (right < (int)len && array[right] > array[largest])
		largest = right;

	if (largest != idx)
	{
		int temp = array[idx];

		array[idx] = array[largest];
		array[largest] = temp;
		print_array(array, size);
		heapify(array, size, largest, len);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending order using Heap sort
 * @array: Array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (size < 2 || !array)
		return;


	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		int temp = array[0];

		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		heapify(array, size, 0, i);
	}
}

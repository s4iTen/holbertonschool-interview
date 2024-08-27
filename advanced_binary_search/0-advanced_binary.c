#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, size_t left, size_t right)
{
	printf("Searching in array: ");
	for (size_t i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
		{
			printf(", ");
		}
	}
	printf("\n");
}

int binary_search_rec(int *array, size_t left, size_t right, int value)
{
	if (right >= left)
	{
		size_t mid = left + (right - left) / 2;

		print_array(array, left, right);

		if ((mid == left || array[mid - 1] < value) && array[mid] == value)
		{
			return (mid);
		}

		if (array[mid] >= value)
		{
			return (binary_search_rec(array, left, mid, value));
		}

		return (binary_search_rec(array, mid + 1, right, value));
	}

	return (-1);
}

int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
	{
		return (-1);
	}

	return (binary_search_rec(array, 0, size - 1, value));
}

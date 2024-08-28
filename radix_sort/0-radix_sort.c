#include "sort.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * find_max_int - finds the highest value in an array of integers
 *
 * @array: array of values to be searched
 * @size: number of elements in array
 * Return: highest value in array
 */
int find_max_int(int *array, size_t size)
{
	int max;
	size_t i;

	if (!array)
	{
		fprintf(stderr, "find_max_int: NULL array\n");
		return (0);
	}

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * build_buckets - allocates memory for arrays in `buckets`
 *
 * @buckets: array of arrays to be allocated
 * @bucket_sizes: array containing amounts of members for arrays in `buckets`
 */
void build_buckets(int *bucket_sizes, int **buckets)
{
	int *bucket;
	int i;

	if (!bucket_sizes || !buckets)
	{
		fprintf(stderr, "build_buckets: NULL parameters\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < 10; i++)
	{
		bucket = malloc(sizeof(int) * bucket_sizes[i]);
		if (!bucket)
		{
			fprintf(stderr, "build_buckets: malloc failure\n");
			for (; i > -1; i--)
				free(buckets[i]);
			free(buckets);
			exit(EXIT_FAILURE);
		}

		buckets[i] = bucket;
	}
}

/**
 * into_array - copies sorted values from `buckets` back into `array`
 *
 * @array: array of values to be sorted
 * @size: number of elements in array
 * @buckets: array of arrays each containing sorted members of original array
 * @bucket_sizes: array containing amounts of members for arrays in `buckets`
 */
void into_array(int *array, size_t size, int **buckets, int *bucket_sizes)
{
	int i, j, k;

	for (i = 0, k = 0; i < 10; i++)
	{
		for (j = 0; j < bucket_sizes[i]; j++, k++)
			array[k] = buckets[i][j];
	}

	print_array(array, size);

	for (i = 0; i < 10; i++)
		free(buckets[i]);
}

/**
 * radix_sort - sorts array of integers in ascending order using radix sort
 * @array: array of values to be sorted
 * @size: number of elements in array
 */
void radix_sort(int *array, size_t size)
{
	int **buckets;
	int bucket_sizes[10], bucket_fill_levels[10];
	int max, max_digits, pass, divisor, digit;
	size_t i;

	if (!array || size < 2)
		return;
	buckets = malloc(sizeof(int *) * 10);
	if (!buckets)
		exit(EXIT_FAILURE);
	max = find_max_int(array, size);
	for (max_digits = 0; max > 0; max_digits++)
		max /= 10;
	for (pass = 0, divisor = 1; pass < max_digits; pass++, divisor *= 10)
	{
		memset(bucket_sizes, 0, sizeof(int) * 10);
		memset(bucket_fill_levels, 0, sizeof(int) * 10);
		for (i = 0; i < size; i++)
		{
			digit = (array[i] / divisor) % 10;
			bucket_sizes[digit]++;
		}
		build_buckets(bucket_sizes, buckets);
		for (i = 0; i < size; i++)
		{
			digit = (array[i] / divisor) % 10;
			buckets[digit][bucket_fill_levels[digit]] = array[i];
			bucket_fill_levels[digit]++;
		}
		into_array(array, size, buckets, bucket_fill_levels);
	}
	free(buckets);
}

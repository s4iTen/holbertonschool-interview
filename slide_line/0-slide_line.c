#include "slide_line.h"

/**
 * merge_values - Merge contiguous equal values in an array based on direction
 * @line: Pointer to the array of integers
 * @size: Size of the array
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 */
void merge_values(int *line, size_t size, int direction)
{
	size_t i, j;

	if (direction == SLIDE_LEFT)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (line[i] == line[i + 1])
			{
				line[i] *= 2;
				line[i + 1] = 0;
			}
		}
	}
	else if (direction == SLIDE_RIGHT)
	{
		for (j = size - 1; j > 0; j--)
		{
			if (line[j] == line[j - 1])
			{
				line[j] *= 2;
				line[j - 1] = 0;
			}
		}
	}
}

/**
 * shift_values - Shift non-zero values to the specified direction
 * @line: Pointer to the array of integers
 * @size: Size of the array
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 */
void shift_values(int *line, size_t size, int direction)
{
	size_t i, j;
	int temp;

	if (direction == SLIDE_LEFT)
	{
		for (i = 0, j = 0; i < size; i++)
		{
			if (line[i] != 0)
			{
				temp = line[i];
				line[i] = 0;
				line[j++] = temp;
			}
		}
	}
	else if (direction == SLIDE_RIGHT)
	{
		for (i = size; i > 0; i--)
		{
			if (line[i - 1] != 0)
			{
				temp = line[i - 1];
				line[i - 1] = 0;
				line[--j] = temp;
			}
		}
	}
}


/**
 * slide_line - Slide and merge an array of integers to the specified direction
 * @line: Pointer to the array of integers
 * @size: Size of the array
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 * Return: 1 if successful, 0 if failed
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	shift_values(line, size, direction);
	merge_values(line, size, direction);
	shift_values(line, size, direction);

	return (1);
}

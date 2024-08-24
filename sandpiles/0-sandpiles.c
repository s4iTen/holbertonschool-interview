#include "sandpiles.h"
#include <stdio.h>
#include <stdbool.h>

/**
 * print_grid - Print a 3x3 grid
 * @grid: 3x3 grid
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stable - Check if a sandpile is stable (all cells <= 3)
 * @grid: 3x3 grid
 * Return: true if stable, false if not
 */
bool is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				return (false);
			}
		}
	}
	return (true);
}

/**
 * sandpiles_sum - Compute the sum of two sandpiles
 * @grid1: 3x3 grid (stable)
 * @grid2: 3x3 grid (stable)
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int topple_grid[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	while (!is_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					if (i > 0)
						topple_grid[i - 1][j]++;
					if (i < 2)
						topple_grid[i + 1][j]++;
					if (j > 0)
						topple_grid[i][j - 1]++;
					if (j < 2)
						topple_grid[i][j + 1]++;
					grid1[i][j] -= 4;
				}
			}
		}

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				grid1[i][j] += topple_grid[i][j];
				topple_grid[i][j] = 0;
			}
		}
	}
}

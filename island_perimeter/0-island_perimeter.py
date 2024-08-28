#!/usr/bin/python3

""" Function to find perimiter of an island """


def island_perimeter(grid):
    """
    Calculate the perimeter of an island (1s) in a 2D grid, where 0s represent water.
    Returns 0 if the grid is empty or has no land cells.
    """

    if not grid:
        return 0

    perimeter = 0
    rows, cols = len(grid), len(grid[0])

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                perimeter += 4

                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 1
                if i < rows - 1 and grid[i + 1][j] == 1:
                    perimeter -= 1
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 1
                if j < cols - 1 and grid[i][j + 1] == 1:
                    perimeter -= 1

    return perimeter

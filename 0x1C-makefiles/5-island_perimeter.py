#!/usr/bin/python3
"""
This module represents a perimeter calculation function
"""


def island_perimeter(grid):
    """
    Calculate the perimeter of the island described in the grid.

    Args:
        grid (list of list of int): A 2D grid where
            1 represents land, and
            0 represents water.

    Returns:
        int: The perimeter of the island.
    """
    if not grid:
        return 0

    perimeter = 0
    rows, cols = len(grid), len(grid[0])

    for row in range(rows):
        for col in range(cols):
            if grid[row][col] == 1:
                perimeter += 4

                # Check adjacent cells and subtract the shared sides.
                if row > 0 and grid[row - 1][col] == 1:
                    perimeter -= 1
                if row < rows - 1 and grid[row + 1][col] == 1:
                    perimeter -= 1
                if col > 0 and grid[row][col - 1] == 1:
                    perimeter -= 1
                if col < cols - 1 and grid[row][col + 1] == 1:
                    perimeter -= 1

    return perimeter

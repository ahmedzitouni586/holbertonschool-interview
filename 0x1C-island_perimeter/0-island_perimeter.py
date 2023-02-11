#!/usr/bin/python3
"""
island_perimeter:
function  that returns the perimeter of the island described in grid
"""

def island_perimeter(grid):
    if not grid:
        return 0
    row = len(grid)
    col = len(grid[0])
    perimeter = 0
    for i in range(row):
        for j in range(col):
            if grid[i][j] == 1:
                perimeter += 4
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2
    return perimeter
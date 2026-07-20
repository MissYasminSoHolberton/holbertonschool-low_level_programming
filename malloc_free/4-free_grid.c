#include <stdlib.h>

/**
 * free_grid - frees 2d grid array
 * @grid: grid to free
 * @height: height of the grid
 */
void free_grid(int **grid, int height)
{
	int i;

	i = 0;

	while (i < height)
	{
		free(grid[i]);
		i++;
	}

	free(grid);
}

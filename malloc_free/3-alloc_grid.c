#include <stdlib.h>

/**
 * alloc_grid - maked a 2d array
 * @width: width of the array
 * @height: height of the array
 *
 * Return: pointer to the 2d array
 */
int **alloc_grid(int width, int height)
{
	int **array;
	int i;
	int j;

	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}

	array = malloc(sizeof(int *) * height);

	i = 0;
	j = 0;
	while (i < height)
	{
		array[i] = malloc(sizeof(int) * width);
		j = 0;
		while (j < width)
		{
			array[i][j] = 0;
			j++;
		}
		i++;
	}

	return (array);
}

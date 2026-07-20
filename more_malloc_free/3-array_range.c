#include <stdlib.h>

/**
 * array_range - allocates memory that is the size of the range
 * @min: low range of the array
 * @max: high range of the array
 *
 * Return: address to the allocated memory
 */
int *array_range(int min, int max)
{
	int *result;
	int i;
	int size;

	if (min > max)
	{
		return (NULL);
	}

	size = max - min + 1;
	if (size < 0)
		size *= -1;

	result = malloc(sizeof(int) * size);

	if (result == NULL)
	{
		return (NULL);
	}

	i = 0;
	while (i < size)
	{
		result[i] = min + i;
		i++;
	}

	return (result);
}

#include <stdlib.h>

/**
 * malloc_checked - allocates memory and returns the pointer
 * @b: number of bytes
 *
 * Return: pointer to the created string or 98 if unsuccessful
 */
void *malloc_checked(unsigned int b)
{
	void *array;

	array = malloc(b);

	if (array == NULL)
	{
		exit(98);
	}

	return (array);
}

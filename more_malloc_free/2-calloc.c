#include <stdlib.h>

/**
 * _calloc - allocates memory with contents set as 0
 * @nmemb: number or members
 * @size: size of each member
 *
 * Return: address to the allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *result;
	unsigned int i;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}

	result = malloc(nmemb * size);

	if (result == NULL)
	{
		return (NULL);
	}

	i = 0;
	while (i < nmemb * size)
	{
		((char *)result)[i] = 0;
		i++;
	}

	return (result);
}

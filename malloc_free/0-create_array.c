#include <stdlib.h>

/**
 * create_array - creates an array of chars, and with a specific char
 * @size: size of array
 * @c: character to add in the array
 *
 * Return: pointer to the created char array
 */
char *create_array(unsigned int size, char c)
{
	char *char_array;
	unsigned int i;

	char_array = malloc(sizeof(c) * size);

	if (char_array == NULL || size == 0)
	{
		return (NULL);
	}

	i = 0;
	while (i < size)
	{
		char_array[i] = c;
		i++;
	}

	return (char_array);
}

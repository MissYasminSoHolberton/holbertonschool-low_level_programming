#include <stdlib.h>

/**
 * _strdup - copies a string to a new string
 * @str: string to copy
 *
 * Return: pointer to the created string or NULL if unsuccessful
 */
char *_strdup(char *str)
{
	char *char_array;
	int i;
	int size;

	size = sizeof(str) + 1;
	char_array = malloc(size);

	if (char_array == NULL || size == 0)
	{
		return (NULL);
	}

	i = 0;
	while (i <= size)
	{
		char_array[i] = str[i];
		i++;
	}

	return (char_array);
}

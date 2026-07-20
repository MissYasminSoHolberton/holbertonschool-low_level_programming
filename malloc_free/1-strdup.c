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

	if (str == NULL)
	{
		return (NULL);
	}

	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		size++;
		i++;
	}

	char_array = malloc(size + 1);

	if (char_array == NULL)
	{
		return (NULL);
	}

	i = 0;
	while (str[i] != '\0')
	{
		char_array[i] = str[i];
		i++;
	}

	return (char_array);
}

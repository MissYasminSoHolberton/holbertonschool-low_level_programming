#include <stdlib.h>

/**
 * _strlen - gets the length of a string
 * @str:string
 *
 * Return: length of string
 */
int _strlen(char *str)
{
	int len;
	int i;

	len = 0;
	i = 0;

	while (str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

/**
 * str_concat - copies two strings to a new string
 * @s1: string 1
 * @s2: string 2
 *
 * Return: pointer to the created string or NULL if unsuccessful
 */
char *str_concat(char *s1, char *s2)
{
	char *char_array;
	int i;
	int size;

	if (s1 == NULL)
	{
		s1 = "";
	}

	if (s2 == NULL)
	{
		s2 = "";
	}

	i = 0;
	size = _strlen(s1) + _strlen(s2);

	char_array = malloc(size + 1);

	if (char_array == NULL)
	{
		return (NULL);
	}

	i = 0;
	while (*s1 != '\0')
	{
		char_array[i] = *s1;
		s1++;
		i++;
	}

	while (*s2 != '\0')
	{
		char_array[i] = *s2;
		s2++;
		i++;
	}

	char_array[i] = '\0';

	return (char_array);
}

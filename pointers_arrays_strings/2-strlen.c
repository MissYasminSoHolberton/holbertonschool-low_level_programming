#include "main.h"

/**
 * _strlen - gets the length of the string
 * @s: string input
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int length;
	int i;

	i = 0;
	length = 0;

	while (s[i] != '\0')
	{
		length++;
		i++;
	}
	return (length);
}

#include "main.h"
#include <stddef.h>

/**
 * _strpbrk - points to the memory that has the first occurence of string
 * @s: string input
 * @accept: array of char to check
 *
 * Return: number of bytes
 */
char *_strpbrk(char *s, char *accept)
{
	int i;
	int found;

	i = 0;
	found = 0;

	while (*s != '\0')
	{
		i = 0;
		found = 0;

		while (accept[i] != '\0')
		{
			if (*s == accept[i])
			{
				found = 1;
				break;
			}
			i++;
		}

		if (found == 1)
		{
			return (s);
		}

		s++;
	}

	return (NULL);
}

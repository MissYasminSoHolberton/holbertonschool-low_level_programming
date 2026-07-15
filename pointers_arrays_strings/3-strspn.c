#include "main.h"

/**
 * _strspn - gets the bytes of char you accept
 * @s: string input
 * @accept: char to accept
 *
 * Return: number of bytes
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int result;
	int i;
	int found;

	result = 0;

	while (*s != '\0')
	{
		found = 0;
		i = 0;

		while (accept[i] != '\0')
		{
			if (*s == accept[i])
			{
				found = 1;
				break;
			}
			i++;
		}

		if (found == 0)
		{
			break;
		}

		s++;
		result++;
	}
	return (result);
}

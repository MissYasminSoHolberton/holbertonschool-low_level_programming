#include "main.h"
#include <stddef.h>

/**
 * _strstr - finds the first occurance of the substring
 * @haystack: string to look into
 * @needle: string to look for
 *
 * Return: location of the first instance of the neddle string
 */
char *_strstr(char *haystack, char *needle)
{
	int i;

	while (*haystack != '\0')
	{
		i = 0;

		while (haystack[i] == needle[i])
		{
			i++;
		}

		if (needle[i] == '\0')
		{
			return (haystack);
		}

		haystack++;
	}
	return (NULL);
}

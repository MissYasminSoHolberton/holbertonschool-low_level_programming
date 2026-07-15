#include "main.h"
#include <stddef.h>

/**
 * _strchr - search for the first orrurance of a char
 * @s: string input
 * @c: char to find
 *
 * Return: address of first instance of char
 */
char *_strchr(char *s, char c)
{
	while (*s != c && *s != '\0')
	{
		s++;
	}

	if (*s != c)
	{
		return NULL;
	}

	return (s);
}

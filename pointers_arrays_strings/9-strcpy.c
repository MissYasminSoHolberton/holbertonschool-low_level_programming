#include "main.h"
#include <stdio.h>

/**
 * _strcpy - copy src to dest
 * @dest: array to be copied to
 * @src: original array
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

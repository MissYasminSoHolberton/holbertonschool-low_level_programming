#include "main.h"
#include <stdio.h>

/**
 * _strcmp - compare two strings
 * @s1: string input 1
 * @s2: string input 2
 *
 * Return: difference of two strings
 */
int _strcmp(char *s1, char *s2)
{
	int result;

	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}

	result = *s1 - *s2;

	return (result);
}

#include "main.h"

/**
 * _memset - edits memory based on b and n
 * @s: memory address
 * @b: constant byte
 * @n: number of byte to change
 *
 * Return: address to edited memory
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;
	char *start_of_s;

	i = 0;
	start_of_s = s;

	while (i < n)
	{
		*s = b;
		s++;
		i++;
	}
	return (start_of_s);
}

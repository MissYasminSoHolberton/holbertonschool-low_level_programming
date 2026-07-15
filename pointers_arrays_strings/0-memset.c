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

	i = 0;

	while (i < n)
	{
		*s = b;
		s++;
		i++;
	}
	return (s);
}

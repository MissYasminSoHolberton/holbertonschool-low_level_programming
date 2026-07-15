#include "main.h"

/**
 * _memset - fills the first n bytes of the memory area pointed to by s with the constant byte b
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

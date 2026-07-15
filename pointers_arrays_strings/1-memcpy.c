#include "main.h"

/**
 * _memcpy - function copies n bytes from memory area src to memory area dest
 * @dest: destination memory
 * @src: source memory
 * @n: number of byte to change
 *
 * Return: address to edited memory
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;
	char *start_of_s;

	i = 0;
	start_of_s = src;

	while (i < n)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	return (start_of_s);
}

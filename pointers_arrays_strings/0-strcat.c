#include "main.h"
#include <stdio.h>

/**
 * get_len - get length of the string
 * @str: string input
 *
 * Return: length of the string
 */
int get_len(char *str)
{
	int len;

	len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * _strcat - combines both strings and assigns it to dest
 * @src: first string
 * @dest: second string and the output of the concatination
 *
 * Return: the concatinated string
 */
char *_strcat(char *dest, char *src)
{
	int src_len;
	int dest_len;
	int index;

	src_len = get_len(src);
	dest_len = get_len(dest);
	printf("%d\n",src_len);
	printf("%d\n",dest_len);
	index = 0;

	while (index < src_len)
	{
		dest[dest_len + index] = src[index];
		index++;
	}

	return (dest);
}

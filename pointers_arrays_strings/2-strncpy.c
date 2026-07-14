#include "main.h"

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
 * _strncpy - replaces the elements of string
 * @src: first string
 * @dest: second string and the output of the concatination
 * @n: end of copy
 *
 * Return: output string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int src_len;
	int dest_len;
	int i;

	src_len = get_len(src);
	dest_len = get_len(dest);
	i = 0;

	while (i < n && i <= dest_len && i < src_len && src[0] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	return (dest);
}

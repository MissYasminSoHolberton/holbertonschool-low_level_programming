#include <stdlib.h>

/**
 * _strlen - gets the length of a string
 * @str:string
 *
 * Return: length of string
 */
int _strlen(char *str)
{
	int len;
	int i;

	len = 0;
	i = 0;

	while (str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

/**
 * string_nconcat - concatinates two strings
 * @s1: string 1
 * @s2: string 2
 * @n: number of bytes of the second string to add
 *
 * Return: pointer to the created string or NULL if unsuccessful
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *char_array;
	int i;
	unsigned int j;
	unsigned int s1size;
	unsigned int s2size;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	i = 0;
	s1size = _strlen(s1);
	s2size = _strlen(s2);
	if (n < s2size)
		s2size = n;

	char_array = malloc(s1size + s2size  + 1);

	if (char_array == NULL)
		return (NULL);

	i = 0;
	while (*s1 != '\0')
	{
		char_array[i] = *s1;
		s1++;
		i++;
	}
	j = 0;
	while (*s2 != '\0' && j < n)
	{
		char_array[i] = *s2;
		s2++;
		i++;
		j++;
	}
	char_array[i] = '\0';
	return (char_array);
}

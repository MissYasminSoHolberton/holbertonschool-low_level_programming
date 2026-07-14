#include "main.h"
#include <stdio.h>

/**
 * string_toupper - transfroms string to its uppercase form
 * @str: input string
 *
 * Return: address to edited pointer
 */
char *string_toupper(char *str)
{
	int i;

	i = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - ('a' - 'A');
		}
		i++;
	}
	return (str);
}

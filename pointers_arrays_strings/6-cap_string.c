#include "main.h"
#include <stdio.h>

/**
 * cap_string - capitalize every word in a string
 * @str: input string
 *
 * Return: address to edited pointer
 */
char *cap_string(char *str)
{
	int i;
	int j;
	char *separators;
	int is_separator;

	separators = " \t\n,;.!?\"(){}";

	i = 0;
	j = 0;

	while (str[i+1] != '\0')
	{
		is_separator = 0;
		j = 0;
		while(separators[j] != '\0')
		{
			if (separators[j] == str[i])
			{
				is_separator = 1;
			}
			j++;
		}
		if (is_separator == 1)
		{
			if (str[i+1] >= 'a' && str[i+1] <= 'z')
				{
					str[i+1] = str[i+1] - ('a' - 'A');
				}
		}
		i++;
	}
	return (str);
}

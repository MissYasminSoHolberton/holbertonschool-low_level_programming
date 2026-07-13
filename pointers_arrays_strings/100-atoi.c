#include "main.h"
#include <stdio.h>

/**
 * _atoi - removes all non number string
 * @s: input string
 *
 * Return: 0 no numbers in string, else return the string with only numbers
 */
int _atoi(char *s)
{
	int result;
	int i;
	int sign;

	i = 0;
	sign = 1;
	result = 0;

	while (s[i] != '\0' && !(s[i] >= '0' && s[i] <= '9'))
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}

	while (s[i] != '\0' && s[i] >= '0' && s[i] <= '9')
	{
		if (sign == -1)
		{
			result = result * 10 - (s[i] - '0');
		}
		else
		{
			result = result * 10 + (s[i] - '0');
		}
		i++;
	}

	return (result);
}

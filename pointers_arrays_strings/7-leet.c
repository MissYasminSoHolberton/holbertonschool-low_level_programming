#include "main.h"

/**
 * leet - translate string to leet code
 * @str: input string
 *
 * Return: address to edited string
 */
char *leet(char *str)
{
	char *letters;
	char *digits;

	int i;
	int j;

	letters = "aAeEoOtTlL";
	digits = "4433007711";
	j = 0;

	while (str[j] != '\0')
	{
		i = 0;
		while (letters[i] != '\0')
		{
			if (str[j] == letters[i])
			{
				str[j] = digits[i];
				break;
			}
			i++;
		}
		j++;
	}
	return (str);
}

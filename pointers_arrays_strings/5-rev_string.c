#include "main.h"

/**
 * rev_string - prints the input string and its reverse
 * @s: string to print
 */
void rev_string(char *s)
{
	int length;
	int i;
	char temp;

	length = 0;
	i = 0;

	while (s[length] != '\0')
	{
		length++;
	}

	length--;

	while (length >= i)
	{
		temp = s[i];
		s[i] = s[length];
		s[length] = temp;

		length--;
		i++;
	}
}

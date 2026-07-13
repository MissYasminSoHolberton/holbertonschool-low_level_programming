#include "main.h"

/**
 * print_rev - print string in reverse
 * @s: string to print in reverse
 */
void print_rev(char *s)
{
	int length;

	length = 0;

	while (s[length] != '\0')
	{
		length++;
	}

	while (length >= 0)
	{
		_putchar(s[length]);
		length--;
	}
	_putchar('\n');
}

#include "main.h"

/**
 * puts_half - prints half of the string
 * @str: string input
 */
void puts_half(char *str)
{
	int length;
	int i;

	length = 0;

	while (str[length] != '\0')
	{
		length++;
	}
	
	i = length / 2;
	length--;

	while (i <= length)
	{
		_putchar(str[i]);
		i++;	
	}
	_putchar('\n');
}

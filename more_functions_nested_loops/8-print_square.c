#include "main.h"

/**
 * print_square - print a square of size n
 * @size: size of square
 */

void print_square(int size)
{
	int i;
	int j;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (i = 1; i <= size; i++)
	{
		if (size <= 0)
		{
			_putchar('0');
			break;
		}

		for (j = 1; j <= size; j++)
		{
			_putchar('#');
		}
		_putchar('\n');
	}
}

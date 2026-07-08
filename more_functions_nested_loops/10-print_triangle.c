#include "main.h"

/**
 * print_triangle - print a triangle
 * @size: size of the triangle
 */

void print_triangle(int size)
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

		for (j = size; j >= 1; j--)
		{
			if (j <= i)
			{
				_putchar('#');
			}
			else
			{
				_putchar(' ');
			}
		}

		_putchar('\n');
	}
}

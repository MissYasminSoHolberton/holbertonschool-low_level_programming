#include "main.h"

/**
 * print_diagonal - print diagonal line with width and height of n
 * @n: width and height of diagonal line
 */

void print_diagonal(int n)
{
	int i;
	int j;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}

	for (i = 1; i <= n; i++)
	{
		if (n <= 0)
		{
			_putchar('0');
			break;
		}

		for (j = 1; j <= n; j++)
		{
			if (j <= i)
			{
				if (j == i)
				{
					_putchar('\\');
				}
				else
				{
					_putchar(' ');
				}
			}
		}
		_putchar('\n');
	}
}

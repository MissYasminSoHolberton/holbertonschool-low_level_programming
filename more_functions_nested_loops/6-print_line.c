#include "main.h"

/**
 * print_line - print _ depending on input
 * @n: number of _ to print
 */

void print_line(int n)
{
	int i;

	for (i = 1; i <= n; i++)
	{
		if (n <= 0)
		{
			break;
		}
		_putchar('_');
	}
	_putchar('\n');
}

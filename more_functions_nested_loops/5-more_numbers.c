#include "main.h"

/**
 * more_numbers - print numbers from 0 to 14, 10 times
 */

void more_numbers(void)
{
	int i;
	int row;

	for (row = 1; row <= 10; row++)
	{
		for (i = 0; i <= 14; i++)
		{
			if (i >= 10)
			{
				_putchar((i / 10) + '0');
			}
			_putchar((i % 10) + '0');
		}
		_putchar('\n');
	}
}

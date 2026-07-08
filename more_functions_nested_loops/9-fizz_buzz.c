#include <stdio.h>

/**
 * main - print numbers 1 - 100, and fizzbuzz
 *
 * Return: 0 always (success)
 */

int main(void)
{
	int i;
	int lastnum = 100;

	for (i = 1; i <= lastnum; i++)
	{
		if (i % 3 != 0 && i % 5 != 0)
		{
			printf("%d", i);
		}
		if (i % 3 == 0)
		{
			printf("Fizz");
		}
		if (i % 5 == 0)
		{
			printf("Buzz");
		}
		if (i != lastnum)
		{
			printf(" ");
		}
	}
	printf("\n");
	return (0);
}

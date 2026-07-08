#include <stdio.h>

/**
 * main - print numbers 1 - 100, anything divisible by 3 will print fizz and anything divisible by 5 will print buzz
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

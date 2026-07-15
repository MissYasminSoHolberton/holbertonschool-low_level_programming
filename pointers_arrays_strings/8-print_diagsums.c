#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sum of the diagonal
 * @a: 2d array input
 * @size: size of the array
 */
void print_diagsums(int *a, int size)
{
	int sum1;
	int sum2;
	int i;

	sum1 = 0;
	sum2 = 0;
	i = 0;

	while (i < size)
	{
		sum1 = sum1 + a[i * size + i];
		sum2 = sum2 + a[i * size + size - i - 1];
		i++;
	}

	printf("%d, %d\n", sum1, sum2);
}

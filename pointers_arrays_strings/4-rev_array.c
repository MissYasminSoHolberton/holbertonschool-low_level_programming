#include "main.h"
#include <stdio.h>

/**
 * reverse_array - reverse an array
 * @a: input array
 * @n: number of elements to reverse
 */
void reverse_array(int *a, int n)
{
	int i;
	int tmp;

	i = 0;
	n = n - 1;

	while (n > i)
	{
		tmp = a[i];
		a[i] = a[n];
		a[n] = tmp;

		n--;
		i++;
	}
}

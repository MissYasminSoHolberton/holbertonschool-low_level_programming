#include "main.h"
#include <stdio.h>

/**
 * print_array - print array items
 * @a: array input
 * @n: number of elemets to be printed
 */
void print_array(int *a, int n)
{
	int i;

	i = 1;
	
	if (i < n)
	{
		printf("%d", a[0]);
	}

	while (i < n)
	{
		printf(", %d", a[i]);
		i++;
	}
	printf("\n");
}

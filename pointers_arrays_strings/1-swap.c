#include "main.h"

/**
 * swap_int - swaps the values of two inputs
 * @a: number 1
 * @b: number 2
 */
void swap_int(int *a, int *b)
{
	int a_value;
	int b_value;

	a_value = *a;
	b_value = *b;
	*a = b_value;
	*b = a_value;
}

#include <stdio.h>
#include "math.h"

/**
 * add - adding two integers
 */
void add(void)
{
	int num1;
	int num2;

	printf("A: ");
	scanf("%d", &num1);
	printf("B: ");
	scanf("%d", &num2);

	printf("Result: %d\n", num1 + num2);
}

#include "main.h"
#include <stdio.h>

/**
 * print_to_98 - print to 98 from input number with formart
 * @n: input
 *
 * Return: always void
 */
void print_to_98(int n)
{
if (n < 98)
{
while (n < 98)
{
printf("%d, ", n);
n++;
}
}
else if (n > 98)
{
while (n > 98)
{
printf("%d, ", n);
n--;
}
}
printf("98\n");
}

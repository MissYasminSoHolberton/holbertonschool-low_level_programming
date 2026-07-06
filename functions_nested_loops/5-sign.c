#include "main.h"

/**
 * print_sign - prints sign of number
 * @n: number to check
 *
 * Return: if n is > 0 return 1, else if n == 0 return 0, else -1
 */
int print_sign(int n)
{
if (n > 0)
{
_putchar('+');
return (1);
}
else if (n == 0)
{
_putchar('0');
return (0);
}
_putchar('-');
return (-1);
}
